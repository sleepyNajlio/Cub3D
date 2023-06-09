/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:23:16 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/09 13:31:25 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_dir_v(t_data *data, int i)
{
	data->rays[i].isfacingdown = (data->rays[i].ray_angle > 0
			&& data->rays[i].ray_angle < M_PI);
	data->rays[i].isfacingup = !(data->rays[i].isfacingdown);
	data->rays[i].isfacingright = (data->rays[i].ray_angle < M_PI_2
			|| data->rays[i].ray_angle > (M_PI * 1.5));
	data->rays[i].isfacingleft = !(data->rays[i].isfacingright);
}

void	first_inter_v(t_data *data, int i)
{
	data->rays[i].xintercept = floor(data->player->x / CELL_SIZE) * CELL_SIZE;
	if (data->rays[i].isfacingright)
		data->rays[i].xintercept += CELL_SIZE;
	data->rays[i].yintercept = data->player->y
		+ (data->rays[i].xintercept - data->player->x)
		* tan(data->rays[i].ray_angle);
}

void	x_y_step_v(t_data *data, int i)
{
	data->rays[i].xstep = CELL_SIZE;
	if (data->rays[i].isfacingleft)
		data->rays[i].xstep *= -1;
	data->rays[i].ystep = CELL_SIZE * tan(data->rays[i].ray_angle);
	if (data->rays[i].isfacingup && data->rays[i].ystep > 0)
		data->rays[i].ystep *= -1;
	if (data->rays[i].isfacingdown && data->rays[i].ystep < 0)
		data->rays[i].ystep *= -1;
	data->rays[i].nxt_ver_x_inter = data->rays[i].xintercept;
	data->rays[i].nxt_ver_y_inter = data->rays[i].yintercept;
}

void	stop_inc_v(t_data *data, int i)
{
	data->rays[i].ver_wall_hit_x = data->rays[i].nxt_ver_x_inter;
	data->rays[i].ver_wall_hit_y = data->rays[i].nxt_ver_y_inter;
}

void	inc_ray_v(t_data *data, int i)
{
	data->rays[i].nxt_ver_x_inter += data->rays[i].xstep;
	data->rays[i].nxt_ver_y_inter += data->rays[i].ystep;
}
