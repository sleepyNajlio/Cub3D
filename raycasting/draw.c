/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/24 05:42:28 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_player(t_data *data)
{
	double	x;
	double	y;
	double	angle;

	x = data->player->x;
	y = data->player->y;
	angle = data->player->angle;
	draw_circle(data->img, x - CELL_SIZE / 2, y - CELL_SIZE / 2,
		CELL_SIZE / 2, RED);
	draw_line(data->img, x, y, x + cos(angle) * CELL_SIZE / 2,
		y + sin(angle) * CELL_SIZE / 2, BLUE);
}

void	draw_ray(t_data *data)
{
	double	x;
	double	y;
	int i;

	i = 0;
	x = data->player->x;
	y = data->player->y;
	while (i < data->rays->num_rays)
	{
		draw_line(data->img, x, y, x + cos(data->rays[i].ray_angle) * CELL_SIZE*2,
				y + sin(data->rays[i].ray_angle) * CELL_SIZE*2, GREEN);
		i++;
	}
}

void	main_draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img->img = mlx_new_image(data->mlx,
			data->parse->map_width * CELL_SIZE,
			data->parse->map_height * CELL_SIZE);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (data->parse->map[i][j] == '1')
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, BLUE);
			else
			{
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, WHITE);
				draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, i * CELL_SIZE, BLACK);
				draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, j * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
				draw_line(data->img, (j + 1) * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
				draw_line(data->img, j * CELL_SIZE, (i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
			}
			j++;
		}
		i++;
	}

	raycasting(data);
	
	draw_player(data);
	// for(int ll = 0; ll < data->rays->num_rays; ll++)
	draw_ray(data);		
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}