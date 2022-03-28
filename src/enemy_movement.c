/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:08:48 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:07:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static void	static_execute_enemy_move(t_data *data, int direction)
{
	set_delta(data, direction);
	put_tile(data, data->enemy.x, data->enemy.y, SPACE_IMAGE);
	data->enemy.x += data->dx;
	data->enemy.y += data->dy;
	put_enemy(data);
}

static void	static_enemy_move_random(t_data *data)
{
	int	direction;
	int	count;

	count = 0;
	while (count < MAXTRYS)
	{
		direction = generate_random_number_from_1_to_max(data, 4);
		set_delta(data, direction);
		if (is_valid_enemy_position(data, data->enemy.x
				+ data->dx, data->enemy.y + data->dy))
		{
			static_execute_enemy_move(data, direction);
			break ;
		}
		count ++;
	}
}

void	enemy_move_vertical(t_data *data)
{
	int	direction;

	direction = data->player.y - data->enemy.y;
	if (direction > 0)
	{
		if (is_valid_enemy_position(data, data->enemy.x, data->enemy.y + 1))
			static_execute_enemy_move(data, DOWN);
		else
			static_enemy_move_random(data);
	}
	else if (direction < 0)
	{
		if (is_valid_enemy_position(data, data->enemy.x, data->enemy.y - 1))
			static_execute_enemy_move(data, UP);
		else
			static_enemy_move_random(data);
	}
	else
		enemy_move_horizontal(data);
}

void	enemy_move_horizontal(t_data *data)
{
	int	direction;

	direction = data->player.x - data->enemy.x;
	if (direction > 0)
	{
		if (is_valid_enemy_position(data, data->enemy.x + 1, data->enemy.y))
			static_execute_enemy_move(data, RIGHT);
		else
			static_enemy_move_random(data);
	}
	else if (direction < 0)
	{
		if (is_valid_enemy_position(data, data->enemy.x - 1, data->enemy.y))
			static_execute_enemy_move(data, LEFT);
		else
			static_enemy_move_random(data);
	}
	else
		enemy_move_vertical(data);
}

void	move_enemy(t_data *data)
{
	int	direction;

	if (data->enemy.status == false)
		return ;
	direction = generate_random_number_from_1_to_max(data, 2);
	if (direction % 2)
		enemy_move_horizontal(data);
	else
		enemy_move_vertical(data);
	if (data->enemy.x == data->player.x && data->enemy.y == data->player.y)
		show_menu(data, "You lost!");
}
