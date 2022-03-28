/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:25:57 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:25:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "so_long.h"
# include "exit.h"
# include "map.h"
# include "enemy.h"
# include "random.h"
# include "timer.h"
# include "player.h"

# define INTERVAL 3

void	start_game(t_data *data);

#endif