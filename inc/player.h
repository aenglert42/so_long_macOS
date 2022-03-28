/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:13 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:26:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "exit.h"
# include "map.h"
# include "enemy.h"
# include "random.h"
# include "timer.h"
# include "utils.h"

void	move_player(t_data **data, int direction);

#endif