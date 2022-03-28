/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:42:18 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:58:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	static_put_tile_to_image(t_data *data, int x, int y)
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

static void	static_create_map(t_data *data)
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
				data->player.x = x;
				data->player.y = y;
			}
			else if (data->map[y][x] == LOOT)
				data->loot_count += 1;
			if (data->map[y][x] != SPACE)
				static_put_tile_to_image(data, x, y);
			x++;
		}
		y++;
	}
}

void	iterate_map(t_data *data, int tile)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			put_tile(data, x, y, tile);
			data->grid.width = x;
			x++;
		}
		data->grid.height = y;
		y++;
	}
}

void	display_map(t_data *data)
{
	iterate_map(data, SPACE_IMAGE);
	static_create_map(data);
	put_countbar(data);
	put_player(data);
	set_enemies(data);
}
