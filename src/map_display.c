/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:44 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 21:41:50 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	static_ft_put_tile_to_image(t_data *data, int x, int y)
{
	int	i;

	if (data->map[y][x] == WALL)
		i = WALL_IMAGE;
	else if (data->map[y][x] == EXIT)
		i = EXIT_IMAGE;
	else if (data->map[y][x] == LOOT)
		i = LOOT_IMAGE;
	else
		i = SPACE_IMAGE;
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i]->img,
		x * data->img_size, y * data->img_size);
}

static void	static_ft_create_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == START)
			{
				data->p_x = x;
				data->p_y = y;
			}
			else if (data->map[y][x] == LOOT)
				data->loot_count += 1;
			if (data->map[y][x] != SPACE)
				static_ft_put_tile_to_image(data, x, y);
			x++;
		}
		y++;
	}
}

static void	static_ft_create_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			ft_put_space(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_display_map(t_data *data)
{
	static_ft_create_background(data);
	static_ft_create_map(data);
	ft_put_player(data);
}
