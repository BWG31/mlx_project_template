/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:04:13 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 14:36:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	divide_tuple(t_tuple t, float d)
{
	if (equal(d, 0))
	{
		tp_error("divide_tuple", TP_DIV_ERROR);
		return (t);
	}
	return ((t_tuple){t.x / d, t.y / d, t.z / d, t.w});
}
