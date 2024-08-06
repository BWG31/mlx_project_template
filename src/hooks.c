/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:24:45 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:47:03 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx->win, DestroyNotify, 0, close_editor, data);
	mlx_loop_hook(data->mlx->xvar, NULL, NULL); // SET LOOP FUNCTION
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, keypress, data);
	mlx_hook(data->mlx->win, ButtonPress, ButtonPressMask, mouse_down, data);
	mlx_hook(data->mlx->win, ButtonRelease, ButtonReleaseMask, mouse_up, data);
	mlx_hook(data->mlx->win, MotionNotify, PointerMotionMask, mouse_move, data);
}
