/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:06:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 13:24:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

int	timer(t_data *data)
{
	if (data->timer == OFF)
		return (EXIT_SUCCESS);
	data->timer++;
	if (data->timer == 1000)
	{
		move_enemy(data);
	}
	else if (data->timer == 3000)
	{
		data->timer = 0;
	}
	return (EXIT_SUCCESS);
}
