/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:07:39 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 17:31:41 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ray_dire(t_data *data, int i)
{
	data->rays[i].isfacingdown = (data->rays[i].ray_angle > 0
			&& data->rays[i].ray_angle < M_PI);
	data->rays[i].isfacingup = !(data->rays[i].isfacingdown);
	data->rays[i].isfacingright = (data->rays[i].ray_angle < M_PI_2
			|| data->rays[i].ray_angle > (M_PI * 1.5));
	data->rays[i].isfacingleft = !(data->rays[i].isfacingright);
}

void	first_inter_h(t_data *data, int i)
{
	data->rays[i].yintercept = floor(data->player->y / CELL_SIZE) * CELL_SIZE;
	if (data->rays[i].isfacingdown)
		data->rays[i].yintercept += CELL_SIZE;
	data->rays[i].xintercept = data->player->x
		+ (data->rays[i].yintercept - data->player->y)
		/ tan(data->rays[i].ray_angle);
}

void	x_y_step_h(t_data *data, int i)
{
	data->rays[i].ystep = CELL_SIZE;
	if (data->rays[i].isfacingup)
		data->rays[i].ystep *= -1;
	data->rays[i].xstep = CELL_SIZE / tan(data->rays[i].ray_angle);
	if (data->rays[i].isfacingleft && data->rays[i].xstep > 0)
		data->rays[i].xstep *= -1;
	if (data->rays[i].isfacingright && data->rays[i].xstep < 0)
		data->rays[i].xstep *= -1;
	data->rays[i].nxt_horz_x_inter = data->rays[i].xintercept;
	data->rays[i].nxt_horz_y_inter = data->rays[i].yintercept;
}

void	stop_inc(t_data *data, int i)
{
	data->rays[i].hor_wall_hit_x = data->rays[i].nxt_horz_x_inter;
	data->rays[i].hor_wall_hit_y = data->rays[i].nxt_horz_y_inter;
}

void	inc_ray(t_data *data, int i)
{
	data->rays[i].nxt_horz_x_inter += data->rays[i].xstep;
	data->rays[i].nxt_horz_y_inter += data->rays[i].ystep;
}
