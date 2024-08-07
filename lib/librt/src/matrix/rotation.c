/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:58:00 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 10:56:16 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_m4x4	x_rotate_matrix(float r)
{
	return ((t_m4x4){{\
		{1, 0, 0, 0}, \
		{0, cos(r), -sin(r), 0}, \
		{0, sin(r), cos(r), 0}, \
		{0, 0, 0, 1}}});
}

static t_m4x4	y_rotate_matrix(float r)
{
	return ((t_m4x4){{\
		{cos(r), 0, sin(r), 0}, \
		{0, 1, 0, 0}, \
		{-sin(r), 0, cos(r), 0}, \
		{0, 0, 0, 1}}});
}

static t_m4x4	z_rotate_matrix(float r)
{
	return ((t_m4x4){{\
		{cos(r), -sin(r), 0, 0}, \
		{sin(r), cos(r), 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}});
}

t_m4x4	mx_rotation(float radians, int axis)
{
	t_m4x4	m;

	if (axis < X_AXIS || axis > Z_AXIS)
	{
		mx_error("mx_rotation", MX_AXIS_ERROR);
		m = mx_identity();
	}
	else if (axis == X_AXIS)
		m = x_rotate_matrix(radians);
	else if (axis == Y_AXIS)
		m = y_rotate_matrix(radians);
	else if (axis == Z_AXIS)
		m = z_rotate_matrix(radians);
	return (m);
}

t_m4x4	mx_add_rotation(t_m4x4 m, float radians, int axis)
{
	return (mx_mult(mx_rotation(radians, axis), m));
}
