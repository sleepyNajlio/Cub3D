/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:32:58 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/09 13:25:24 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_img *img, double x, double y, int color)
{
	int	i;
	int	j;
	int	size;

	size = CELL_SIZE * MINIMAP_SCALE_FACTOR;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;
	int	radius;

	radius = CELL_SIZE * MINIMAP_SCALE_FACTOR / 2;
	i = 0;
	while (i < radius * 2)
	{
		j = 0;
		while (j < radius * 2)
		{
			if (sqrt((radius - i) * (radius - i) + (radius - j) \
			* (radius - j)) <= radius)
				my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
