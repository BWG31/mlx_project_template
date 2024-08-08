/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:19:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/08 17:30:51 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_reflection(int axis)
{
	if (axis < 0 || axis > Z_AXIS)
	{
		mx_error("mx_reflection", MX_AXIS_ERROR);
		return (mx_identity());
	}
	if (axis == X_AXIS)
		return (mx_scaling(-1, 1, 1));
	if (axis == Y_AXIS)
		return (mx_scaling(1, -1, 1));
	if (axis == Z_AXIS)
		return (mx_scaling(1, 1, -1));
	return (mx_identity());
}

t_m4x4	mx_add_reflection(t_m4x4 m, int axis)
{
	return (mx_mult(mx_reflection(axis), m));
}
