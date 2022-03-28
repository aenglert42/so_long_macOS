/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:19:57 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 12:50:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

static unsigned long	static_sum_of_digits(unsigned long number)
{
	unsigned long	sum;

	sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return (sum);
}

static unsigned short	static_myrand(unsigned short lfsr)
{
	unsigned short	bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = (lfsr >> 1) | (bit << 15);
	return (lfsr);
}

unsigned int	generate_random_number_from_1_to_max(t_data *data, int max)
{
	data->rand = static_myrand(data->rand);
	return (data->rand % max + 1);
}

void	generate_seed(t_data *data)
{
	unsigned long	seed;

	seed = (unsigned long)&seed;
	seed = static_sum_of_digits(seed);
	data->rand = ((unsigned int)seed);
}
