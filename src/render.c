/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:57:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:44:56 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	render(t_data *data)
{
	reset_image(data);
	// RENDER INSTRUCTONS
	mlx_put_image_to_window(data->mlx->xvar, data->mlx->win, \
							data->mlx->img, 0, 0);
}
