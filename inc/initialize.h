/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:00 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:26:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H
# include "../libft/inc/libft.h"
# include "so_long.h"

void	initialize_data_struct(t_data *data);
void	initialize_buffer_with(char *buffer, char c, int len);

#endif