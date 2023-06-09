/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:35:25 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/09 13:31:30 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	tex_id(t_data *data, int i)
{
	if (!data->rays[i].was_hit_vertical)
	{
		if (data->rays[i].isfacingup)
			return (1);
		else
			return (0);
	}
	else
	{
		if (data->rays[i].isfacingright)
			return (3);
		else
			return (2);
	}
}

unsigned int	get_pixel(t_text *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	wall_height(t_data *data, int i)
{
	data->rays[i].corr_wall_dis = data->rays[i].distance
		* cos(data->rays[i].ray_angle - data->player->angle);
	data->rays[i].project_plan_dis = (SCREEN_WIDTH / 2)
		/ tan(data->rays[i].fov_angle / 2);
	data->rays[i].wall_strip_height = (CELL_SIZE / data->rays[i].corr_wall_dis)
		* data->rays[i].project_plan_dis;
}

void	start_end(t_data *data, int i, int w_h)
{
	data->rays[i].start = (SCREEN_HEIGHT / 2) - (w_h / 2);
	if (data->rays[i].start < 0)
		data->rays[i].start = 0;
	data->rays[i].end = (SCREEN_HEIGHT / 2) + (w_h / 2);
	if (data->rays[i].end > SCREEN_HEIGHT)
		data->rays[i].end = SCREEN_HEIGHT - 1;
}

void	render3dprojection(t_data *data, int i)
{
	int	w_h;
	int	off_x;
	int	off_y;
	int	y;
	int	id;

	wall_height(data, i);
	w_h = (int)data->rays[i].wall_strip_height;
	start_end(data, i, w_h);
	y = data->rays[i].start;
	if (data->rays[i].was_hit_vertical)
		off_x = (int)data->rays[i].wall_y % CELL_SIZE;
	else
		off_x = (int)data->rays[i].wall_x % CELL_SIZE;
	id = tex_id(data, i);
	while (y < data->rays[i].end)
	{
		off_y = (y +((float)w_h / (float)2) - (SCREEN_HEIGHT / 2))
			* ((float)data->text[id].txt_h / (float)w_h);
		my_mlx_pixel_put(data->img, i, y,
			get_pixel(&data->text[id], off_x, off_y));
		y++;
	}
}
