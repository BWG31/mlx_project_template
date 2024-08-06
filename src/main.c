/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:20:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:21:45 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

int	main(void)
{
	t_data	*data;

	data = init_data();
	set_hooks(data);
	mlx_loop(data->mlx->xvar);
	destroy_data(data);
	return (0);
}
