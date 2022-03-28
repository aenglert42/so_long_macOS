/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:17 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:26:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H
# include "../libft/inc/libft.h"
# include "so_long.h"

void			generate_seed(t_data *data);
unsigned int	generate_random_number_from_1_to_max(t_data *data, int max);

#endif