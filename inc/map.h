/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:04 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 22:00:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/inc/libft.h"
# include "exit.h"
# include "initialize.h"
# include "so_long.h"
# include "enemy.h"

int		count_lines(char *filepath);
void	read_map(t_data *data, char *filepath);
void	check_map(t_data *data, int numberoflines);
void	display_map(t_data *data);
void	put_tile(t_data *data, int x, int y, int tile);
void	put_player(t_data *data);
void	put_enemy(t_data *data);
void	put_countbar(t_data *data);
void	check_setup(char **map, bool *errorflags, int columns, int lines);
void	load_images(t_data *data);
void	iterate_map(t_data *data, int tile);

#endif