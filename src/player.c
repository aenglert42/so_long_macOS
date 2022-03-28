/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:39:57 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:22:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	static_display_new_movementcount(t_data **data)
{
	put_countbar(*data);
	free((*data)->move_count_str);
	(*data)->move_count_str = join_and_free("movements ",
			ft_itoa((*data)->move_count));
	display_movementcount(*data);
}

static void	static_execute_player_move(t_data **data)
{
	(*data)->move_count += 1;
	static_display_new_movementcount(data);
	put_tile(*data, (*data)->player.x, (*data)->player.y, SPACE_IMAGE);
	(*data)->player.x += (*data)->dx;
	(*data)->player.y += (*data)->dy;
	if ((*data)->map[(*data)->player.y][(*data)->player.x] == LOOT)
	{
		(*data)->map[(*data)->player.y][(*data)->player.x] = SPACE;
		put_tile(*data, (*data)->player.x, (*data)->player.y, SPACE_IMAGE);
		(*data)->loot_count -= 1;
	}
	else if ((*data)->enemy.x == (*data)->player.x
		&& (*data)->enemy.y == (*data)->player.y)
		show_menu(*data, "You lost!");
	else if ((*data)->map[(*data)->player.y][(*data)->player.x] == EXIT)
	{
		put_player(*data);
		show_menu(*data, "You won!");
	}
	put_player(*data);
}

static bool	static_is_valid_move(t_data **data, int dx, int dy)
{
	char	c;

	c = (*data)->map[(*data)->player.y + dy][(*data)->player.x + dx];
	if (c == WALL)
		return (false);
	else if (c == EXIT && (*data)->loot_count != 0)
		return (false);
	else
		return (true);
}

void	move_player(t_data **data, int direction)
{
	set_delta(*data, direction);
	if (static_is_valid_move(data, (*data)->dx, (*data)->dy))
		static_execute_player_move(data);
}
