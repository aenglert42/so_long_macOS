/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:26:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "exit.h"
# include "map.h"

# define CHARWIDTH 3
# define CHARHEIGHT 15

void	show_menu(t_data *data, char *str);

#endif