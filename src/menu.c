/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:42:10 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:48:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

static int	static_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit_program(data);
	return (EXIT_SUCCESS);
}

void	show_menu(t_data *data, char *str)
{
	int		len;

	data->timer = OFF;
	len = 10 * CHARWIDTH;
	mlx_string_put(data->mlx, data->win, (data->grid.width / 2)
		* data->img_size - len, (data->grid.height / 2) * data->img_size,
		ORANGE, str);
	mlx_string_put(data->mlx, data->win, (data->grid.width / 2)
		* data->img_size - len, (data->grid.height / 2) * data->img_size
		+ CHARHEIGHT, ORANGE, "Press ESC to exit.");
	mlx_hook(data->win, KeyPress, KeyPressMask, static_key_hook, data);
	mlx_loop(data->mlx);
}
