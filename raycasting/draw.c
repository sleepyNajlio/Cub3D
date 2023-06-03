/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 16:52:38 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_player(t_data *data)
{
	double	x;
	double	y;
	int		scale;

	scale = CELL_SIZE * MINIMAP_SCALE_FACTOR;
	x = data->player->x * MINIMAP_SCALE_FACTOR;
	y = data->player->y * MINIMAP_SCALE_FACTOR;
	draw_circle(data->img, x - scale / 2, y - scale / 2, scale / 2, RED);
	draw_line(data->img, x * MINIMAP_SCALE_FACTOR, y * MINIMAP_SCALE_FACTOR,
		(x + cos(data->player->angle) * scale / 2) * MINIMAP_SCALE_FACTOR,
		(y + sin(data->player->angle) * scale / 2) * MINIMAP_SCALE_FACTOR,
		BLUE);
}

void	draw_ray(t_data *data)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	x = data->player->x * MINIMAP_SCALE_FACTOR;
	y = data->player->y * MINIMAP_SCALE_FACTOR;
	while (i < data->rays->num_rays)
	{
		draw_line(data->img, x, y, data->rays[i].wall_x * MINIMAP_SCALE_FACTOR,
			data->rays[i].wall_y * MINIMAP_SCALE_FACTOR, RED);
		i++;
	}
}

void	floor_ceiling(t_data *data, int ii, int j)
{
	while (ii < SCREEN_HEIGHT / 2)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(data->img, j, ii, data->parse->ceiling);
			j++;
		}
		ii++;
	}
	ii = SCREEN_HEIGHT / 2;
	while (ii < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(data->img, j, ii, data->parse->floor);
			j++;
		}
		ii++;
	}
}

void	minimap(t_data *data, int i, int j)
{
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (data->parse->map[i][j] == '1')
				draw_square(data->img, j * CELL_SIZE * MINIMAP_SCALE_FACTOR,
					i * CELL_SIZE * MINIMAP_SCALE_FACTOR,
					CELL_SIZE * MINIMAP_SCALE_FACTOR, BLUE);
			j++;
		}
		i++;
	}
}

void	main_draw(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
	floor_ceiling(data, 0, 0);
	raycasting(data);
	minimap(data, 0, 0);
	draw_ray(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
