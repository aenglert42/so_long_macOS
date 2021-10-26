/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:29:13 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/20 15:29:14 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H
# include "../libft/includes/libft.h"
# include "so_long.h"

void	ft_initialize(t_data *data);
void	ft_initialize_buffer_with(char *buffer, char c, int len);

#endif