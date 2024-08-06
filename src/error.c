/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:49:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:22:41 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

void	exit_error(t_data *data, char *message)
{
	if (errno)
		perror(message);
	else
		ft_putendl_fd(message, STDERR_FILENO);
	destroy_data(data);
	exit(EXIT_FAILURE);
}
