/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:06:46 by bgolding          #+#    #+#             */
/*   Updated: 2024/08/06 17:47:17 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_project_template.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_editor(data));
	// ADD OTHER KEY HANDLERS HERE
	return (0);
}
