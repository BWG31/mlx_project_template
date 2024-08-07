/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjugate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:25:50 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 16:01:18 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_adjugate(t_m4x4 m)
{
	t_m4x4	cofactor_matrix;
	int		i;
	int		j;

	i = 0;
	while (i < MAT4X4_SIZE)
	{
		j = 0;
		while (j < MAT4X4_SIZE)
		{
			cofactor_matrix.data[i][j] = cofactor_4x4(m, i, j);
			j++;
		}
		i++;
	}
	return (mx_transpose(cofactor_matrix));
}
