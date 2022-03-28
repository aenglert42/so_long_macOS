/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:42:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:50:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize_buffer_with(char *buffer, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
}

static void	static_set_height(t_data *data)
{
	data->window.height = 0;
	while (data->map[data->window.height] != NULL)
		data->window.height += 1;
	data->window.height *= data->img_size;
	data->window.height += COUNTBAR;
}

static void	static_set_width(t_data *data)
{
	int	len;

	len = ft_strlen(*data->map);
	data->window.width = len * data->img_size;
}

void	initialize_data_struct(t_data *data)
{
	data->player.side = PLAYER_IMAGE;
	data->loot_count = 0;
	data->move_count = 0;
	data->counter = 0;
	data->timer = OFF;
	data->img_size = TILE_SIZE;
	static_set_width(data);
	static_set_height(data);
	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &data->screen.width, &data->screen.height);
	while ((data->window.width > data->screen.width
			|| data->window.height > data->screen.height - WINDOWBAR - COUNTBAR)
		&& data->img_size > PIXELLIMIT)
	{
		data->img_size /= 2;
		static_set_width(data);
		static_set_height(data);
	}
}
