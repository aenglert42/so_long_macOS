/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:40 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 09:10:21 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	static_ft_count_map_element(char **map, int element)
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

static bool	static_ft_vertical_wall_is_complete(char **map, int column)
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

static bool	static_ft_horizontal_wall_is_complete(char *line)
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

static bool	static_ft_is_closed_by_walls(char **map, int columns, int lines)
{
	if (!static_ft_horizontal_wall_is_complete(map[0]))
		return (false);
	if (!static_ft_horizontal_wall_is_complete(map[lines - 1]))
		return (false);
	if (!static_ft_vertical_wall_is_complete(map, 0))
		return (false);
	if (!static_ft_vertical_wall_is_complete(map, columns - 1))
		return (false);
	return (true);
}

void	ft_check_setup(char **map, char *errorflag, int columns, int lines)
{
	if (!static_ft_is_closed_by_walls(map, columns, lines))
		errorflag[4] = '1';
	if (static_ft_count_map_element(map, LOOT) < 1)
		errorflag[7] = '1';
	if (static_ft_count_map_element(map, EXIT) < 1)
		errorflag[6] = '1';
	if (static_ft_count_map_element(map, START) != 1)
		errorflag[5] = '1';
}
