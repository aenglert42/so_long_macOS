/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:40:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:12:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "exit.h"
#include "initialize.h"
#include "map.h"
#include "game.h"

static bool	static_is_valid_filetype(char *filepath, char *filetype)
{
	int		pathlen;
	int		typelen;
	char	*fileending;

	pathlen = strlen(filepath);
	typelen = strlen(filetype);
	fileending = filepath + pathlen - typelen;
	if (!ft_strcmp_n(fileending, filetype, typelen))
		return (true);
	return (false);
}

static void	static_preinitialize_data_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < ERRORS)
	{
		data->errorflags[i] = 0;
		i++;
	}
	data->imgs[0] = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->move_count_str = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*filepath;

	static_preinitialize_data_struct(&data);
	if (argc > 2)
		exit_error(&data, ARGUMENTS);
	if (argc < 2)
		exit_error(&data, NOFILE);
	filepath = argv[1];
	if (!static_is_valid_filetype(filepath, ".ber"))
		exit_error(&data, WRONGFILE);
	read_map(&data, filepath);
	initialize_data_struct(&data);
	start_game(&data);
	return (EXIT_SUCCESS);
}
