/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:19:08 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 14:29:10 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	vector_magnitude(t_vector vec)
{
	if (vec.w != VECTOR)
		tp_error("vector_magnitude", TP_MAG_ERROR);
	return (sqrtf(fsquaref(vec.x) + fsquaref(vec.y) + fsquaref(vec.z)));
}
