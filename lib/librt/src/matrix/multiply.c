/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:32:32 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:47:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static float	matrix_dot(t_m4x4 left, int row, t_m4x4 right, int col)
{
	float	product;
	int		i;

	product = 0;
	i = 0;
	while (i < MAT4X4_SIZE && i < MAT4X4_SIZE)
	{
		product += left.data[row][i] * right.data[i][col];
		i++;
	}
	return (product);
}

t_m4x4	mx_mult(t_m4x4 left, t_m4x4 right)
{
	t_m4x4	new_matrix;
	int		i;
	int		j;

	i = 0;
	while (i < MAT4X4_SIZE)
	{
		j = 0;
		while (j < MAT4X4_SIZE)
		{
			new_matrix.data[i][j] = matrix_dot(left, i, right, j);
			j++;
		}
		i++;
	}
	return (new_matrix);
}

static float	dot_row_tuple(float *row, t_tuple t)
{
	return (row[0] * t.x + row[1] * t.y + row[2] * t.z + row[3] * t.w);
}

t_tuple	mx_mult_tuple(t_m4x4 m, t_tuple t)
{
	return ((t_tuple){dot_row_tuple(m.data[0], t), \
						dot_row_tuple(m.data[1], t), \
						dot_row_tuple(m.data[2], t), \
						dot_row_tuple(m.data[3], t)});
}

t_m4x4	mx_mult_float(t_m4x4 m, float f)
{
	t_m4x4	product;
	int		i;
	int		j;

	i = 0;
	while (i < MAT4X4_SIZE)
	{
		j = 0;
		while (j < MAT4X4_SIZE)
		{
			product.data[i][j] = m.data[i][j] * f;
			j++;
		}
		i++;
	}
	return (product);
}
