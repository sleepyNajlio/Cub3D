/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/26 08:16:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_player(t_data *data)
{
	double	x;
	double	y;
	double	angle;
	int		scale;

	
	scale = data->parse->map_scale;
	x = data->player->x;
	y = data->player->y;
	angle = data->player->angle;
	draw_circle(data->img, x - scale / 2, y - scale,
		scale / 2, RED);
	draw_line(data->img, x, y, x + cos(data->player->angle) * scale / 2,
		y + sin(data->player->angle) * scale / 2, BLUE);
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
		//draw hor_ray
		// draw_line(data->img, x, y, data->rays[i].hor_wall_hit_x, data->rays[i].hor_wall_hit_y, GREEN);
		//draw ver_ray
		// draw_line(data->img, x, y, data->rays[i].ver_wall_hit_x, data->rays[i].ver_wall_hit_y, RED);
		draw_line(data->img, x, y, data->rays[i].wall_x, data->rays[i].wall_y, RED);
		i++;
	}
}

void	main_draw(t_data *data)
{
	int	i;
	int	j;
	int map_scale;

	map_scale = data->parse->map_scale;
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
				draw_square(data->img, j * map_scale, i * map_scale, map_scale, BLUE);
			else if (data->parse->map[i][j] == '0')
			{
				draw_square(data->img, j * map_scale, i * map_scale, map_scale, WHITE);
				draw_line(data->img, j * map_scale, i * map_scale, (j + 1) * map_scale, i * map_scale, BLACK);
				draw_line(data->img, j * map_scale, i * map_scale, j * map_scale, (i + 1) * map_scale, BLACK);
				draw_line(data->img, (j + 1) * map_scale, i * map_scale, (j + 1) * map_scale, (i + 1) * map_scale, BLACK);
				draw_line(data->img, j * map_scale, (i + 1) * map_scale, (j + 1) * map_scale, (i + 1) * map_scale, BLACK);
			}
			else
				draw_square(data->img, j * map_scale, i * map_scale, map_scale, GRAY);
			j++;
		}
		i++;
	}

	// raycasting(data);
	
	// draw_ray(data);		
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
