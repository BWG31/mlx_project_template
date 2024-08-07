/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:50:52 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:57:55 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m3x3	submatrix_4x4(t_m4x4 m4, int row, int col)
{
	t_m3x3	m3;
	int		i;
	int		j;
	float	*p;

	i = -1;
	p = (float *)m3.data;
	while (++i < MAT4X4_SIZE)
	{
		if (i == row)
			continue ;
		j = -1;
		while (++j < MAT4X4_SIZE)
		{
			if (j == col)
				continue ;
			*p++ = m4.data[i][j];
		}
	}
	return (m3);
}

t_m2x2	submatrix_3x3(t_m3x3 m3, int row, int col)
{
	t_m2x2	m2;
	int		i;
	int		j;
	float	*p;

	i = -1;
	p = (float *)m2.data;
	while (++i < MAT3X3_SIZE)
	{
		if (i == row)
			continue ;
		j = -1;
		while (++j < MAT3X3_SIZE)
		{
			if (j == col)
				continue ;
			*p++ = m3.data[i][j];
		}
	}
	return (m2);
}
