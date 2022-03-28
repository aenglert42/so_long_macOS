/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:38 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:26:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/inc/libft.h"
# include "so_long.h"

void	set_delta(t_data *data, int direction);
void	display_movementcount(t_data *data);
char	*join_and_free(char const *s1, char *s2);

#endif