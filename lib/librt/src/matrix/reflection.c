/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:19:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 10:50:11 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_reflection(int axis)
{
	t_m4x4	m;

	if (axis < 0 || axis > Z_AXIS)
	{
		mx_error("mx_reflection", MX_AXIS_ERROR);
		m = mx_identity();
	}
	else if (axis == X_AXIS)
		m = mx_scaling(-1, 1, 1);
	else if (axis == Y_AXIS)
		m = mx_scaling(1, -1, 1);
	else if (axis == Z_AXIS)
		m = mx_scaling(1, 1, -1);
	return (m);
}

t_m4x4	mx_add_reflection(t_m4x4 m, int axis)
{
	return (mx_mult(mx_reflection(axis), m));
}
