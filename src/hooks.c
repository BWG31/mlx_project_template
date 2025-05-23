/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:24:45 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/07 09:44:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx->win, DESTROYNOTIFY, 0, close_editor, data);
	mlx_loop_hook(data->mlx->xvar, NULL, NULL); // SET LOOP FUNCTION
	mlx_hook(data->mlx->win, KEYPRESS, KEYPRESSMASK, keypress, data);
	mlx_hook(data->mlx->win, BUTTONPRESS, BUTTONPRESSMASK, mouse_down, data);
	mlx_hook(data->mlx->win, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_up, data);
	mlx_hook(data->mlx->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_move, data);
}
