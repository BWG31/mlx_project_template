/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:53:10 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:08:07 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_vector	normalize_vector(t_vector t)
{
	float	mag;

	if (t.w != VECTOR)
		tp_error("normalize_vector", TP_NORM_ERROR1);
	mag = vector_magnitude(t);
	if (equal(mag, 0))
	{
		tp_error("normalize_vector", TP_NORM_ERROR2);
		return (t);
	}
	return ((t_vector){t.x / mag, t.y / mag, t.z / mag, VECTOR});
}
