/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:30:17 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 14:37:56 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_vector	vector_cross_product(t_vector a, t_vector b)
{
	if (a.w != VECTOR || b.w != VECTOR)
		tp_error("vector_cross_product", TP_CROSS_ERROR);
	return ((t_vector){a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x, \
					VECTOR});
}
