/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:29:05 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 21:24:51 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "../libft/includes/libft.h"
# include "so_long.h"

typedef enum e_errorcode
{
	SUCCESS = 0,
	ERROR1 = 1,
	ERROR2 = 2,
	ERROR3 = 3,
	ERROR4 = 4,
	ERROR5 = 5,
	ERROR6 = 6,
	ERROR7 = 7,
	ERROR8 = 8,
	ERROR9 = 9,
	ERROR10 = 10,
	ERROR11 = 11,
	ERROR12 = 12,
	ERRORS = ERROR12 + 1,
}	t_errorcode;

void	ft_exit_error(t_data *data, char *errorflag);
int		ft_exit_program(t_data *data);
void	ft_free_map(char **map);

#endif