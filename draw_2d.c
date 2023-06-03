/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:32:58 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 22:26:51 by nloutfi          ###   ########.fr       */
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

	radius = CELL_SIZE * MINIMAP_SCALE_FACTOR;
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

void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	d[2];
	int	s[2];
	int	err;
	int	e2;

	d[0] = abs(x1 - x0);
	if (x0 < x1)
		s[0] = 1;
	else
		s[0] = -1;
	d[1] = abs(y1 - y0);
	if (y0 < y1)
		s[1] = 1;
	else
		s[1] = -1;
	if (d[0] > d[1])
		err = d[0] / 2;
	else
		err = -d[1] / 2;
	while (1)
	{
		my_mlx_pixel_put(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -d[0])
		{
			err -= d[1];
			x0 += s[0];
		}
		if (e2 < d[1])
		{
			err += d[0];
			y0 += s[1];
		}
	}
}

// void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int	dx = abs(x1 - x0);
// 	int	sx = x0 < x1 ? 1 : -1;
// 	int	dy = abs(y1 - y0);
// 	int	sy = y0 < y1 ? 1 : -1;
// 	int	err = (dx > dy ? dx : -dy) / 2;
// 	int	e2;

// 	while (1)
// 	{
// 		my_mlx_pixel_put(img, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		e2 = err;
// 		if (e2 > -dx)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dy)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }