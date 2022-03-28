/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:20 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:00:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	static_count_map_element(char **map, int element)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static bool	static_vertical_wall_is_complete(char **map, int column)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		if (map[y][column] != '1')
			return (false);
		y++;
	}
	return (true);
}

static bool	static_horizontal_wall_is_complete(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] != '1')
			return (false);
		x++;
	}
	return (true);
}

static bool	static_is_closed_by_walls(char **map, int columns, int lines)
{
	if (!static_horizontal_wall_is_complete(map[0]))
		return (false);
	if (!static_horizontal_wall_is_complete(map[lines - 1]))
		return (false);
	if (!static_vertical_wall_is_complete(map, 0))
		return (false);
	if (!static_vertical_wall_is_complete(map, columns - 1))
		return (false);
	return (true);
}

void	check_setup(char **map, bool *errorflags, int columns, int lines)
{
	if (!static_is_closed_by_walls(map, columns, lines))
		errorflags[WALLS] = true;
	if (static_count_map_element(map, LOOT) < 1)
		errorflags[NOLOOT] = true;
	if (static_count_map_element(map, EXIT) < 1)
		errorflags[NOEXIT] = true;
	if (static_count_map_element(map, START) != 1)
		errorflags[SPAWN] = true;
}
