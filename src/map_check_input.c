/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:36 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 21:28:49 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	static_ft_is_rectangular(char **map, int numberofcolumns)
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

static bool	static_ft_is_valid_file(char **map)
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

void	ft_check_map(t_data *data, int numberoflines)
{
	int		i;
	char	errorflag[ERRORS + 1];
	int		numberofcolumns;

	ft_initialize_buffer_with(errorflag, '0', ERRORS);
	if (!static_ft_is_valid_file(data->map))
		ft_exit_error(data, "000000001");
	numberofcolumns = ft_strlen(*data->map);
	if (!static_ft_is_rectangular(data->map, numberofcolumns))
		ft_exit_error(data, "0001");
	ft_check_setup(data->map, errorflag, numberofcolumns, numberoflines);
	i = 0;
	while (errorflag[i] != '\0')
	{
		if (errorflag[i] == '1')
			ft_exit_error(data, errorflag);
		i++;
	}
}
