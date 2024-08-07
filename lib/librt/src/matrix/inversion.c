/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:58:07 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 10:48:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4x4	mx_inversion(t_m4x4 m)
{
	float	det;

	det = determinant_4x4(m);
	if (equal(det, 0))
	{
		mx_error("mx_inversion", MX_INV_ERROR);
		return (m);
	}
	return (mx_mult_float(mx_adjugate(m), 1 / det));
}

t_m4x4	mx_add_inversion(t_m4x4 m)
{
	return (mx_mult(mx_inversion(m), m));
}
