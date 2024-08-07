/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:20:19 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 10:51:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_m4x4	shearing_x(float y, float z)
{
	return ((t_m4x4){{\
	{1, y, z, 0}, \
	{0, 1, 0, 0}, \
	{0, 0, 1, 0}, \
	{0, 0, 0, 1}}});
}

static t_m4x4	shearing_y(float x, float z)
{
	return ((t_m4x4){{\
	{1, 0, 0, 0}, \
	{x, 1, z, 0}, \
	{0, 0, 1, 0}, \
	{0, 0, 0, 1}}});
}

static t_m4x4	shearing_z(float x, float y)
{
	return ((t_m4x4){{\
	{1, 0, 0, 0}, \
	{0, 1, 0, 0}, \
	{x, y, 1, 0}, \
	{0, 0, 0, 1}}});
}

t_m4x4	mx_shearing(int axis, float a, float b)
{
	t_m4x4	m;

	if (axis < X_AXIS || axis > Z_AXIS)
	{
		mx_error("mx_rotation", MX_AXIS_ERROR);
		m = mx_identity();
	}
	else if (axis == X_AXIS)
		m = shearing_x(a, b);
	else if (axis == Y_AXIS)
		m = shearing_y(a, b);
	else if (axis == Z_AXIS)
		m = shearing_z(a, b);
	return (m);
}

t_m4x4	mx_add_shearing(t_m4x4 m, int axis, float a, float b)
{
	return (mx_mult(mx_shearing(axis, a, b), m));
}
