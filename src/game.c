/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:05:38 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/25 21:50:41 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	static_ft_move_player(t_data **data, int new_x, int new_y)
{
	(*data)->move_count += 1;
	ft_printf("movements: %d\n", (*data)->move_count);
	ft_put_space(*data, (*data)->p_x, (*data)->p_y);
	(*data)->p_x = new_x;
	(*data)->p_y = new_y;
	if ((*data)->map[(*data)->p_y][(*data)->p_x] == LOOT)
	{
		(*data)->map[(*data)->p_y][(*data)->p_x] = SPACE;
		ft_put_space(*data, (*data)->p_x, (*data)->p_y);
		(*data)->loot_count -= 1;
	}
	else if ((*data)->map[(*data)->p_y][(*data)->p_x] == EXIT)
	{
		ft_put_player(*data);
		ft_printf("You win!\n");
		ft_exit_program(*data);
	}
	ft_put_player(*data);
}

static bool	st_ft_val_move(t_data **data, char c)
{
	if (c == WALL)
		return (false);
	else if (c == EXIT && (*data)->loot_count != 0)
		return (false);
	else
		return (true);
}

static int	static_ft_key_hook(int keycode, t_data **data)
{
	if (keycode == ESC_KEY)
		ft_exit_program(*data);
	else if (keycode == W_KEY)
	{
		if (st_ft_val_move(data, (*data)->map[(*data)->p_y - 1][(*data)->p_x]))
			static_ft_move_player(data, (*data)->p_x, (*data)->p_y - 1);
	}
	else if (keycode == A_KEY)
	{
		if (st_ft_val_move(data, (*data)->map[(*data)->p_y][(*data)->p_x - 1]))
			static_ft_move_player(data, (*data)->p_x - 1, (*data)->p_y);
	}
	else if (keycode == S_KEY)
	{
		if (st_ft_val_move(data, (*data)->map[(*data)->p_y + 1][(*data)->p_x]))
			static_ft_move_player(data, (*data)->p_x, (*data)->p_y + 1);
	}
	else if (keycode == D_KEY)
	{
		if (st_ft_val_move(data, (*data)->map[(*data)->p_y][(*data)->p_x + 1]))
			static_ft_move_player(data, (*data)->p_x + 1, (*data)->p_y);
	}
	return (0);
}

void	ft_start_game(t_data *data)
{
	ft_printf("movements: 0\n");
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_exit_error(data, "");
	ft_load_images(data);
	data->win = mlx_new_window(data->mlx, data->wwidth, data->wheight,
			"so_long");
	if (data->win == NULL)
		ft_exit_error(data, "");
	ft_display_map(data);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, 2, 1L << 0, static_ft_key_hook, &data);
	mlx_hook(data->win, 17, 1L << 17, ft_exit_program, data);
	mlx_loop(data->mlx);
}
