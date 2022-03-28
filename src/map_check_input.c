/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:06:23 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:11:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	static_is_rectangular(char **map, int numberofcolumns)
{
	int	y;
	int	len;

	y = 0;
	while (map[y] != NULL)
	{
		len = ft_strlen(map[y]);
		if (len != numberofcolumns)
			return (false);
		y++;
	}
	return (true);
}

static bool	static_is_valid_file(char **map)
{
	int	x;
	int	y;

	if (*map == NULL || map[0][0] == '\0')
		return (false);
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != WALL && map[y][x] != LOOT &&
				map[y][x] != SPACE && map[y][x] != START && map[y][x] != EXIT)
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

void	check_map(t_data *data, int numberoflines)
{
	int		i;
	int		numberofcolumns;

	if (!static_is_valid_file(data->map))
		exit_error(data, WRONGFILE);
	numberofcolumns = ft_strlen(*data->map);
	if (!static_is_rectangular(data->map, numberofcolumns))
		exit_error(data, SHAPE);
	check_setup(data->map, data->errorflags, numberofcolumns, numberoflines);
	i = 0;
	while (i < ERRORS)
	{
		if (data->errorflags[i] == true)
			exit_error(data, SETUP);
		i++;
	}
}
