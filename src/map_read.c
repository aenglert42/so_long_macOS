/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:53 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/25 21:57:47 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_count_lines(char *filepath)
{
	int		fd;
	char	*line;
	int		linecount;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_exit_error(NULL, "00000000001");
	linecount = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		linecount++;
		free(line);
		line = ft_gnl(fd);
	}
	if (close(fd) == -1)
		ft_exit_error(NULL, "000000000001");
	return (linecount);
}

void	ft_replace_char1_with_char2(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
}

static void	static_ft_init_map(char	**map, int numberoflines)
{
	int	i;
	
	i = 0;
	while (i <= numberoflines)
	{
		map[i] = NULL;
		i++;
	}
}

void	ft_read_map(t_data *data, char *filepath)
{
	int		fd;
	int		numberoflines;
	int		y;

	numberoflines = ft_count_lines(filepath);
	data->map = malloc(sizeof(char *) * (numberoflines + 1));
	if (data->map == NULL)
		ft_exit_error(NULL, "0000000001");
	static_ft_init_map(data->map, numberoflines);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_exit_error(data, "00000000001");
	y = 0;
	while (y < numberoflines)
	{
		data->map[y] = ft_gnl(fd);
		if (data->map[y] == NULL)
			ft_exit_error(data, "0000000001");
		ft_replace_char1_with_char2(data->map[y], '\n', '\0');
		y++;
	}
	data->map[numberoflines] = NULL;
	if (close(fd) == -1)
		ft_exit_error(data, "000000000001");
	ft_check_map(data, numberoflines);
}
