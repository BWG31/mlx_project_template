/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_macos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:12:56 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:29:00 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->img)
		{
			mlx_destroy_image(mlx->xvar, mlx->img);
			mlx->img = NULL;
		}
		if (mlx->win)
		{
			mlx_destroy_window(mlx->xvar, mlx->win);
			mlx->win = NULL;
		}
		if (mlx->xvar)
		{
			free(mlx->xvar);
			mlx->xvar = NULL;
		}
		free(mlx);
	}
}
