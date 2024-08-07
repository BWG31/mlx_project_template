/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:42:51 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 14:31:19 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	vector_dot_product(t_vector a, t_vector b)
{
	if (a.w != VECTOR || b.w != VECTOR)
		tp_error("vector_dot_product", TP_DOT_ERROR);
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
