/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:57:06 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:25:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	static_key_hook(int keycode, t_data **data)
{
	(*data)->timer = ON;
	if (keycode == ESC_KEY)
		exit_program(*data);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_player(data, UP);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		(*data)->player.side = PLAYER_L_IMAGE;
		put_player(*data);
		move_player(data, LEFT);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(data, DOWN);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		(*data)->player.side = PLAYER_IMAGE;
		put_player(*data);
		move_player(data, RIGHT);
	}
	if (!((*data)->counter % INTERVAL))
		move_enemy(*data);
	(*data)->counter++;
	return (0);
}

void	start_game(t_data *data)
{
	data->move_count_str = join_and_free("movements ",
			ft_itoa(data->move_count));
	load_images(data);
	data->win = mlx_new_window(data->mlx, data->window.width,
			data->window.height, "so_long");
	display_map(data);
	display_movementcount(data);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, DestroyNotify,
		StructureNotifyMask, exit_program, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, static_key_hook, &data);
	mlx_loop_hook(data->mlx, timer, data);
	mlx_loop(data->mlx);
}
