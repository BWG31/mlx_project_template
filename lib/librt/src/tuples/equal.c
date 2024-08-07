/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:32:40 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 13:16:21 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	equal(float a, float b)
{
	return (fabsf(a - b) < EPSILON);
}

bool	equal_tuples(t_tuple a, t_tuple b)
{
	if (!equal(a.x, b.x) || !equal(a.y, b.y) || \
		!equal(a.z, b.z) || !equal(a.w, b.w))
		return (false);
	return (true);
}
