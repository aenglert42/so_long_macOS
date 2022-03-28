/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:08:48 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 15:54:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

bool	is_valid_enemy_position(t_data *data, int x, int y)
{
	if (data->map[y][x] == SPACE)
		return (true);
	else if (data->map[y][x] == START && data->timer != OFF)
		return (true);
	return (false);
}

void	set_enemies(t_data *data)
{
	int	x;
	int	y;
	int	count;

	generate_seed(data);
	data->enemy.status = false;
	count = 0;
	while (count < MAXTRYS)
	{
		x = generate_random_number_from_1_to_max(data, data->grid.width - 1);
		y = generate_random_number_from_1_to_max(data, data->grid.height - 1);
		if (is_valid_enemy_position(data, x, y))
		{
			data->enemy.status = true;
			data->enemy.x = x;
			data->enemy.y = y;
			break ;
		}
		count ++;
	}
	if (data->enemy.status)
		put_enemy(data);
}
