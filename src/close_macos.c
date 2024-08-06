/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_macos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:26:38 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:30:51 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

int	close_editor(t_data *data)
{
	printf("Closing miniRT_editor...\n");
	destroy_data(data);
	exit(EXIT_SUCCESS);
}
