/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:29:19 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 21:26:33 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/includes/libft.h"
# include "exit.h"
# include "initialize.h"
# include "so_long.h"

int		ft_count_lines(char *filepath);
void	ft_read_map(t_data *data, char *filepath);
void	ft_check_map(t_data *data, int numberoflines);
void	ft_display_map(t_data *data);
void	ft_put_space(t_data *data, int x, int y);
void	ft_put_player(t_data *data);
void	ft_check_setup(char **map, char *errorflag, int columns, int lines);
void	ft_load_images(t_data *data);

#endif