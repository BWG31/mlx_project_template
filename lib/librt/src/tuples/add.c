/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:50:30 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 14:26:23 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	if (a.w + b.w > 1)
		tp_error("add_tuple", TP_ADD_ERROR);
	return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}
