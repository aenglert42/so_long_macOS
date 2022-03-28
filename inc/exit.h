/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:25:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 21:59:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "../libft/inc/libft.h"
# include "so_long.h"

void	exit_error(t_data *data, int error);
int		exit_program(t_data *data);
void	free_map(char **map);

#endif