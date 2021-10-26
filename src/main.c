/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:31 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 20:52:01 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "exit.h"
#include "initialize.h"
#include "map.h"
#include "game.h"

static bool	static_ft_is_valid_filetype(char *filepath, char *filetype)
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

int	main(int argc, char **argv)
{
	t_data	data;
	char	*filepath;

	if (argc > 2)
		ft_exit_error(NULL, "01");
	if (argc < 2)
		ft_exit_error(NULL, "001");
	filepath = argv[1];
	if (!static_ft_is_valid_filetype(filepath, ".ber"))
		ft_exit_error(NULL, "000000001");
	ft_read_map(&data, filepath);
	ft_initialize(&data);
	ft_start_game(&data);
	return (EXIT_SUCCESS);
}
