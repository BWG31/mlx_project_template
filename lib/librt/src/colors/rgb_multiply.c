/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:51:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 15:17:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/*	Returns the resulting t_color from multiplying 
	all elements of t_color c by the scalar s. */
t_color	rgb_mult(t_color c, float s)
{
	return ((t_color){c.red * s, c.green * s, c.blue * s});
}
