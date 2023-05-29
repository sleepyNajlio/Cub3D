/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:53:58 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/29 22:01:04 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int has_wall_at(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= data->win_w || y < 0
		|| y >= data->win_h)
		return (0);
	map_x = floor(x / data->parse->cell_size);
	map_y = floor(y / data->parse->cell_size);
	if (data->parse->map[map_y][map_x] == '1')
		return(1);
	else
		return(0);
}

void	hor_rays(t_data *data, int i)
{
	data->rays[i].found_h_wall_hit = 0;
	data->rays[i].hor_wall_hit_x = 0;
	data->rays[i].hor_wall_hit_y = 0;

	// facing_dir(data, i);
	// x_y_first_inter(data, i);
	// delta_x_y(data, i);
	data->rays[i].isfacingdown = (data->rays[i].ray_angle > 0 && data->rays[i].ray_angle < M_PI);
	data->rays[i].isfacingup = !(data->rays[i].isfacingdown);
	data->rays[i].isfacingright = (data->rays[i].ray_angle < M_PI_2 || data->rays[i].ray_angle > (M_PI * 1.5));
	data->rays[i].isfacingleft = !(data->rays[i].isfacingright);	

	data->rays[i].yintercept = floor(data->player->y / data->parse->cell_size) * data->parse->cell_size;
	if (data->rays[i].isfacingdown)
		data->rays[i].yintercept += data->parse->cell_size;

	data->rays[i].xintercept = data->player->x + (data->rays[i].yintercept - data->player->y) / tan(data->rays[i].ray_angle);


	data->rays[i].ystep = data->parse->cell_size;
	if (data->rays[i].isfacingup)
		data->rays[i].ystep *= -1;

	data->rays[i].xstep = data->parse->cell_size / tan(data->rays[i].ray_angle);
	if (data->rays[i].isfacingleft && data->rays[i].xstep > 0)
		data->rays[i].xstep *= -1;
	if (data->rays[i].isfacingright && data->rays[i].xstep < 0)
		data->rays[i].xstep *= -1;


	
	data->rays[i].nxt_horz_x_inter = data->rays[i].xintercept;
	data->rays[i].nxt_horz_y_inter = data->rays[i].yintercept;
	
	while (data->rays[i].nxt_horz_x_inter >= 0 && data->rays[i].nxt_horz_x_inter <= data->win_w
		&& data->rays[i].nxt_horz_y_inter >= 0 && data->rays[i].nxt_horz_y_inter <= data->win_h)
	{
		data->rays[i].found_h_wall_hit = has_wall_at(data,\
			data->rays[i].nxt_horz_x_inter, (data->rays[i].nxt_horz_y_inter - data->rays[i].isfacingup));
		if (data->rays[i].found_h_wall_hit != 0)
		{
			// stop_inc(data,i);
			data->rays[i].hor_wall_hit_x = data->rays[i].nxt_horz_x_inter;
			data->rays[i].hor_wall_hit_y = data->rays[i].nxt_horz_y_inter;
			break;
		}
		else
		{
			// inc_ray(data, i);
			data->rays[i].nxt_horz_x_inter += data->rays[i].xstep;
		data->rays[i].nxt_horz_y_inter += data->rays[i].ystep;
		}
	}
}

void	ver_rays(t_data *data, int i)
{
	data->rays[i].found_v_wall_hit = 0;
	data->rays[i].ver_wall_hit_x = 0;
	data->rays[i].ver_wall_hit_y = 0;

	// facing_dir(data, i);
	// x_y_first_inter(data, i);
	// delta_x_y(data, i);
	data->rays[i].isfacingdown = (data->rays[i].ray_angle > 0 && data->rays[i].ray_angle < M_PI);
	data->rays[i].isfacingup = !(data->rays[i].isfacingdown);
	data->rays[i].isfacingright = (data->rays[i].ray_angle < M_PI_2 || data->rays[i].ray_angle > (M_PI * 1.5));
	data->rays[i].isfacingleft = !(data->rays[i].isfacingright);	

	data->rays[i].xintercept = floor(data->player->x / data->parse->cell_size) * data->parse->cell_size;
	if (data->rays[i].isfacingright)
		data->rays[i].xintercept += data->parse->cell_size;

	data->rays[i].yintercept = data->player->y + (data->rays[i].xintercept - data->player->x) * tan(data->rays[i].ray_angle);


	data->rays[i].xstep = data->parse->cell_size;
	if (data->rays[i].isfacingleft)
		data->rays[i].xstep *= -1;

	data->rays[i].ystep = data->parse->cell_size * tan(data->rays[i].ray_angle);
	if (data->rays[i].isfacingup && data->rays[i].ystep > 0)
		data->rays[i].ystep *= -1;
	if (data->rays[i].isfacingdown && data->rays[i].ystep < 0)
		data->rays[i].ystep *= -1;


	
	data->rays[i].nxt_ver_x_inter = data->rays[i].xintercept;
	data->rays[i].nxt_ver_y_inter = data->rays[i].yintercept;
	
	while (data->rays[i].nxt_ver_x_inter >= 0 && data->rays[i].nxt_ver_x_inter <= data->win_w
		&& data->rays[i].nxt_ver_y_inter >= 0 && data->rays[i].nxt_ver_y_inter <= data->win_h)
	{
		data->rays[i].found_v_wall_hit = has_wall_at(data,\
			(data->rays[i].nxt_ver_x_inter - data->rays[i].isfacingleft), data->rays[i].nxt_ver_y_inter);
		if (data->rays[i].found_v_wall_hit != 0)
		{
			// stop_inc(data,i);
			data->rays[i].ver_wall_hit_x = data->rays[i].nxt_ver_x_inter;
			data->rays[i].ver_wall_hit_y = data->rays[i].nxt_ver_y_inter;
			break;
		}
		else
		{
			// inc_ray(data, i);
			data->rays[i].nxt_ver_x_inter += data->rays[i].xstep;
			data->rays[i].nxt_ver_y_inter += data->rays[i].ystep;
		}
	}
}

double dist_ray(x1, y1, x2, y2) {
    return ( sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) );
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
		v_dis = dist_ray(data->player->x, data->player->y, data->rays[i].ver_wall_hit_x, data->rays[i].ver_wall_hit_y);
	if (data->rays[i].found_h_wall_hit)
		h_dis = dist_ray(data->player->x, data->player->y, data->rays[i].hor_wall_hit_x, data->rays[i].hor_wall_hit_y);

		if (v_dis < h_dis) {
			data->rays[i].wall_x = data->rays[i].ver_wall_hit_x;
			data->rays[i].wall_y = data->rays[i].ver_wall_hit_y;
            data->rays[i].distance = v_dis;
            data->rays[i].was_hit_vertical = 1;
        } else {
            data->rays[i].wall_x = data->rays[i].hor_wall_hit_x;
			data->rays[i].wall_y = data->rays[i].hor_wall_hit_y;
            data->rays[i].distance = h_dis;
            data->rays[i].was_hit_vertical = 0;
        }
}

void	raycasting(t_data *data)
{
	int	i;
	double	ray_angle;

	i = 0;
	ray_angle = data->player->angle - (data->rays->fov_angle / 2);
	while (i < data->rays->num_rays)
	{
		ray_angle = standardized_range(ray_angle);
		data->rays[i].ray_angle = ray_angle;
		cast_ray(data, i);
		render3dProjection(data, i);
		ray_angle += data->rays->fov_angle / data->rays->num_rays;
		i++;
	}
}