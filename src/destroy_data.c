/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:05:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:28:34 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
		destroy_mlx(data->mlx);
	free(data);
}
