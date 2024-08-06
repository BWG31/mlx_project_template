/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:26:04 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:30:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

int	close_editor(t_data *data)
{
	printf("Closing miniRT_editor...\n");
	mlx_loop_end(data->mlx->xvar);
	return (0);
}
