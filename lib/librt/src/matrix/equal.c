/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:46:28 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:43:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
	Compares two t_m4x4 structures for equality.
	Returns false at the first non-equal data element.
	Run-time optimization through pointer arithmetic &
	comparing 4 elements per iteration.
*/
bool	mx_equal(t_m4x4 a, t_m4x4 b)
{
	const int	total_values = MAT4X4_SIZE * MAT4X4_SIZE;
	const float	*ptr_a = (const float *)a.data;
	const float	*ptr_b = (const float *)b.data;
	int			i;

	i = 0;
	while (i < total_values)
	{
		if (ptr_a[i] != ptr_b[i] || ptr_a[i + 1] != ptr_b[i + 1] || \
			ptr_a[i + 2] != ptr_b[i + 2] || ptr_a[i + 3] != ptr_b[i + 3])
			return (false);
		i += MAT4X4_SIZE;
	}
	return (true);
}
