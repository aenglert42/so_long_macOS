/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenglert <aenglert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:48 by aenglert          #+#    #+#             */
/*   Updated: 2021/10/21 21:29:23 by aenglert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	static_ft_putpixelimg(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	static_ft_create_img(t_img *image, t_img *old, int scale)
{
	int				c_x;
	int				c_y;
	unsigned int	color;

	c_x = 0;
	while (c_x < image->iwidth)
	{
		c_y = 0;
		while (c_y < image->iheight)
		{
			color = *(unsigned int *)(old->addr
					+ (unsigned int)(c_y * old->line_length * scale
						+ c_x * scale * (old->bits_per_pixel / 8)));
			static_ft_putpixelimg(image, c_x, c_y, color);
			c_y++;
		}
		c_x++;
	}
}

static t_img	*static_ft_get_img(t_img *old, t_data *data)
{
	t_img	*new;

	new = (t_img *)malloc(sizeof(t_img));
	if (new == NULL)
		ft_exit_error(data, "0000000001");
	new->img = mlx_new_image(data->mlx, data->img_size, data->img_size);
	new->iheight = data->img_size;
	new->iwidth = data->img_size;
	new->addr = mlx_get_data_addr(new->img,
			&new->bits_per_pixel, &new->line_length,
			&new->endian);
	old->addr = mlx_get_data_addr(old->img,
			&old->bits_per_pixel, &old->line_length,
			&old->endian);
	 static_ft_create_img(new, old, old->iwidth / data->img_size);
	return (new);
}

static char	*static_ft_determine_path(int imagenumber)
{
	if (imagenumber == PLAYER_IMAGE)
		return (PLAYER_PATH);
	else if (imagenumber == SPACE_IMAGE)
		return (SPACE_PATH);
	else if (imagenumber == WALL_IMAGE)
		return (WALL_PATH);
	else if (imagenumber == LOOT_IMAGE)
		return (LOOT_PATH);
	else
		return (EXIT_PATH);
}

void	ft_load_images(t_data *data)
{
	t_img	tmp;
	int		i;
	char	*path;

	i = 0;
	while (i < IMAGES)
	{
		path = static_ft_determine_path(i);
		tmp.img = mlx_xpm_file_to_image(data->mlx, path,
				&tmp.iheight, &tmp.iwidth);
		if (tmp.img == NULL)
			ft_exit_error(data, "0000000000001");
		data->imgs[i] = static_ft_get_img(&tmp, data);
		mlx_destroy_image(data->mlx, tmp.img);
		i++;
	}
}
