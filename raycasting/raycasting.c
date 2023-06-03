/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:53:58 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 17:36:17 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	hor_rays(t_data *data, int i)
{
	data->rays[i].found_h_wall_hit = 0;
	data->rays[i].hor_wall_hit_x = 0;
	data->rays[i].hor_wall_hit_y = 0;
	ray_dire(data, i);
	first_inter_h(data, i);
	x_y_step_h(data, i);
	while (data->rays[i].nxt_horz_x_inter >= 0
		&& data->rays[i].nxt_horz_x_inter <= data->win_w
		&& data->rays[i].nxt_horz_y_inter >= 0
		&& data->rays[i].nxt_horz_y_inter <= data->win_h)
	{
		data->rays[i].found_h_wall_hit = has_wall_at(data,
				data->rays[i].nxt_horz_x_inter,
				(data->rays[i].nxt_horz_y_inter - data->rays[i].isfacingup));
		if (data->rays[i].found_h_wall_hit != 0)
		{
			stop_inc(data, i);
			break ;
		}
		else
			inc_ray(data, i);
	}
}

void	ver_rays(t_data *data, int i)
{
	data->rays[i].found_v_wall_hit = 0;
	data->rays[i].ver_wall_hit_x = 0;
	data->rays[i].ver_wall_hit_y = 0;
	ray_dir_v(data, i);
	first_inter_v(data, i);
	x_y_step_v(data, i);
	while (data->rays[i].nxt_ver_x_inter >= 0
		&& data->rays[i].nxt_ver_x_inter <= data->win_w
		&& data->rays[i].nxt_ver_y_inter >= 0
		&& data->rays[i].nxt_ver_y_inter <= data->win_h)
	{
		data->rays[i].found_v_wall_hit = has_wall_at(data,
				(data->rays[i].nxt_ver_x_inter - data->rays[i].isfacingleft),
				data->rays[i].nxt_ver_y_inter);
		if (data->rays[i].found_v_wall_hit != 0)
		{
			stop_inc_v(data, i);
			break ;
		}
		else
			inc_ray_v(data, i);
	}
}

void	cast_ray(t_data *data, int i)
{
	double	v_dis;
	double	h_dis;

	v_dis = INT_MAX;
	h_dis = INT_MAX;
	hor_rays(data, i);
	ver_rays(data, i);
	if (data->rays[i].found_v_wall_hit)
		v_dis = dist_ray(data->player->x, data->player->y,
				data->rays[i].ver_wall_hit_x, data->rays[i].ver_wall_hit_y);
	if (data->rays[i].found_h_wall_hit)
		h_dis = dist_ray(data->player->x, data->player->y,
				data->rays[i].hor_wall_hit_x, data->rays[i].hor_wall_hit_y);
	if (v_dis < h_dis)
		ver_dis(data, i, v_dis);
	else
		hor_dis(data, i, h_dis);
}

void	raycasting(t_data *data)
{
	int		i;
	double	ray_angle;

	i = 0;
	ray_angle = data->player->angle - (data->rays->fov_angle / 2);
	while (i < data->rays->num_rays)
	{
		ray_angle = standardized_range(ray_angle);
		data->rays[i].ray_angle = ray_angle;
		cast_ray(data, i);
		render3dprojection(data, i);
		ray_angle += data->rays->fov_angle / data->rays->num_rays;
		i++;
	}
}
