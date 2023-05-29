/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/29 19:52:54 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void draw_player(t_data *data)
{
	double x;
	double y;
	double angle;
	int scale;

	scale = data->parse->cell_size * MINIMAP_SCALE_FACTOR;
	x = data->player->x * MINIMAP_SCALE_FACTOR;
	y = data->player->y * MINIMAP_SCALE_FACTOR;
	angle = data->player->angle;
	draw_circle(data->img, x - scale / 2, y - scale / 2, scale / 2, RED);
	draw_line(data->img, x * MINIMAP_SCALE_FACTOR, y * MINIMAP_SCALE_FACTOR, (x + cos(data->player->angle) * scale / 2) * MINIMAP_SCALE_FACTOR,
			  (y + sin(data->player->angle) * scale / 2) * MINIMAP_SCALE_FACTOR, BLUE);
}

void draw_ray(t_data *data)
{
	double x;
	double y;
	int i;

	i = 0;
	x = data->player->x * MINIMAP_SCALE_FACTOR;
	y = data->player->y * MINIMAP_SCALE_FACTOR;
	while (i < data->rays->num_rays)
	{
		// draw hor_ray
		//  draw_line(data->img, x, y, data->rays[i].hor_wall_hit_x, data->rays[i].hor_wall_hit_y, GREEN);
		// draw ver_ray
		//  draw_line(data->img, x, y, data->rays[i].ver_wall_hit_x, data->rays[i].ver_wall_hit_y, RED);
		draw_line(data->img, x, y, data->rays[i].wall_x * MINIMAP_SCALE_FACTOR, data->rays[i].wall_y * MINIMAP_SCALE_FACTOR, RED);
		i++;
	}
}

void main_draw(t_data *data)
{
	int i;
	int j;
	int cell_size;

	cell_size = data->parse->cell_size;
	i = 0;
	data->img->img = mlx_new_image(data->mlx,
								   SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img,
										&data->img->bits_per_pixel, &data->img->line_length,
										&data->img->endian);
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (data->parse->map[i][j] == '1')
				draw_square(data->img, j * cell_size * MINIMAP_SCALE_FACTOR, i * cell_size * MINIMAP_SCALE_FACTOR, cell_size * MINIMAP_SCALE_FACTOR, BLUE);
			else if (data->parse->map[i][j] == '0')
			{
				// draw_square(data->img, j * cell_size, i * cell_size, cell_size, WHITE);
				// draw_line(data->img, j * cell_size, i * cell_size, (j + 1) * cell_size, i * cell_size, BLACK);
				// draw_line(data->img, j * cell_size, i * cell_size, j * cell_size, (i + 1) * cell_size, BLACK);
				// draw_line(data->img, (j + 1) * cell_size, i * cell_size, (j + 1) * cell_size, (i + 1) * cell_size, BLACK);
				// draw_line(data->img, j * cell_size, (i + 1) * cell_size, (j + 1) * cell_size, (i + 1) * cell_size, BLACK);

				draw_square(data->img, (j * cell_size) * MINIMAP_SCALE_FACTOR, (i * cell_size) * MINIMAP_SCALE_FACTOR, cell_size * MINIMAP_SCALE_FACTOR, WHITE);
				draw_line(data->img, (j * cell_size) * MINIMAP_SCALE_FACTOR,      (i * cell_size) * MINIMAP_SCALE_FACTOR,        (j + 1) * cell_size* MINIMAP_SCALE_FACTOR, i * cell_size* MINIMAP_SCALE_FACTOR, BLACK);
				draw_line(data->img, (j * cell_size) * MINIMAP_SCALE_FACTOR,      (i * cell_size) * MINIMAP_SCALE_FACTOR,       j * cell_size* MINIMAP_SCALE_FACTOR, (i + 1) * cell_size* MINIMAP_SCALE_FACTOR, BLACK);
				draw_line(data->img, (j + 1) * cell_size * MINIMAP_SCALE_FACTOR,   (i * cell_size) * MINIMAP_SCALE_FACTOR,      (j + 1) * cell_size* MINIMAP_SCALE_FACTOR, (i + 1) * cell_size* MINIMAP_SCALE_FACTOR, BLACK);
				draw_line(data->img, j * cell_size * MINIMAP_SCALE_FACTOR,        (i + 1) * cell_size * MINIMAP_SCALE_FACTOR,  (j + 1) * cell_size* MINIMAP_SCALE_FACTOR, (i + 1) * cell_size* MINIMAP_SCALE_FACTOR, BLACK);
			}
			else
				draw_square(data->img, j * cell_size * MINIMAP_SCALE_FACTOR, i * cell_size * MINIMAP_SCALE_FACTOR, cell_size * MINIMAP_SCALE_FACTOR, GRAY);
			j++;
		}
		i++;
	}

	raycasting(data);

	draw_ray(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
