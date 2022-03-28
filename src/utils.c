/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:32:36 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:23:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_delta(t_data *data, int direction)
{
	data->dx = 0;
	data->dy = 0;
	if (direction == UP)
		data->dy = -1;
	else if (direction == DOWN)
		data->dy = 1;
	else if (direction == LEFT)
		data->dx = -1;
	else if (direction == RIGHT)
		data->dx = 1;
}

void	display_movementcount(t_data *data)
{
	mlx_string_put(data->mlx, data->win, COUNTBAR / 2,
		(data->grid.height + 1) * data->img_size + COUNTBAR * 2 / 3,
		ORANGE, data->move_count_str);
}

char	*join_and_free(char const *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}
