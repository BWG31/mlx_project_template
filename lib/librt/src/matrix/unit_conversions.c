/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:41:47 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 16:17:26 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	deg_to_rad(float degrees)
{
	return (degrees / 180 * M_PI);
}

float	rad_to_deg(float radians)
{
	return (radians * 180 / M_PI);
}
