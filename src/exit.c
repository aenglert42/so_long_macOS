/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:40:32 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:12:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	static_print_errormessage(bool *errorflags)
{
	char	*errormessage[ERRORS];
	int		msglen;
	int		i;

	errormessage[ARGUMENTS] = "Too many arguments!\n";
	errormessage[NOFILE] = "No map-file!\n";
	errormessage[SHAPE] = "Map is not rectangular!\n";
	errormessage[WALLS] = "Map is not surrounded by walls!\n";
	errormessage[SPAWN] = "Invalid number of starting positions!\n";
	errormessage[NOEXIT] = "Map does not have an exit!\n";
	errormessage[NOLOOT] = "Map does not have a collectible!\n";
	errormessage[WRONGFILE] = "Invalid or empty map-file!\n";
	errormessage[MALLOC] = "Malloc failed!\n";
	errormessage[OPEN] = "Open failed!\n";
	errormessage[CLOSE] = "Close failed!\n";
	errormessage[IMAGE] = "Failed to load image!\n";
	write(STDERR_FILENO, "Error\n", 6);
	i = 0;
	while (i < ERRORS)
	{
		msglen = ft_strlen(errormessage[i]);
		if (errorflags[i] == true)
			write(STDERR_FILENO, errormessage[i], msglen);
		i++;
	}
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	destroy_mlx(t_data *data)
{
	int	i;

	i = 0;
	while (data->imgs[i] != NULL && i < IMAGES)
	{
		if (data->mlx != NULL && data->imgs[i]->img != NULL)
		{
			mlx_destroy_image(data->mlx, data->imgs[i]->img);
			free(data->imgs[i]);
		}
		i++;
	}
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
}

void	exit_error(t_data *data, int error)
{	
	if (data != NULL && data->map != NULL)
		free_map(data->map);
	if (data != NULL)
		destroy_mlx(data);
	if (error != SETUP)
		data->errorflags[error] = true;
	static_print_errormessage(data->errorflags);
	exit(EXIT_FAILURE);
}

int	exit_program(t_data *data)
{	
	if (data->map != NULL)
		free_map(data->map);
	destroy_mlx(data);
	free(data->move_count_str);
	exit(EXIT_SUCCESS);
}
