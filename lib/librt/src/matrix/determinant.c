/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:42:41 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 16:19:33 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	determinant_2x2(t_m2x2 m)
{
	return (m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0]);
}

float	cofactor_3x3(t_m3x3 m, int row, int col)
{
	float	det;

	det = determinant_2x2(submatrix_3x3(m, row, col));
	if ((row + col) % 2)
		det *= -1;
	return (det);
}

float	determinant_3x3(t_m3x3 m)
{
	return (m.data[0][0] * cofactor_3x3(m, 0, 0) + \
			m.data[0][1] * cofactor_3x3(m, 0, 1) + \
			m.data[0][2] * cofactor_3x3(m, 0, 2));
}

float	cofactor_4x4(t_m4x4 m, int row, int col)
{
	float	det;

	det = determinant_3x3(submatrix_4x4(m, row, col));
	if ((row + col) % 2)
		det *= -1;
	return (det);
}

float	determinant_4x4(t_m4x4 m)
{
	return (m.data[0][0] * cofactor_4x4(m, 0, 0) + \
			m.data[0][1] * cofactor_4x4(m, 0, 1) + \
			m.data[0][2] * cofactor_4x4(m, 0, 2) + \
			m.data[0][3] * cofactor_4x4(m, 0, 3));
}
