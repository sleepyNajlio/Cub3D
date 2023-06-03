/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:55:02 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 17:33:54 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	has_wall_at(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / CELL_SIZE);
	map_y = floor(y / CELL_SIZE);
	if (map_x < 0 || map_x >= data->parse->map_width || map_y < 0
		|| map_y >= data->parse->map_height)
		return (0);
	if (data->parse->map[map_y][map_x] == '1')
		return (1);
	else
		return (0);
}

double	dist_ray(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ver_dis(t_data *data, int i, double v_dis)
{
	data->rays[i].wall_x = data->rays[i].ver_wall_hit_x;
	data->rays[i].wall_y = data->rays[i].ver_wall_hit_y;
	data->rays[i].distance = v_dis;
	data->rays[i].was_hit_vertical = 1;
}

void	hor_dis(t_data *data, int i, double h_dis)
{
	data->rays[i].wall_x = data->rays[i].hor_wall_hit_x;
	data->rays[i].wall_y = data->rays[i].hor_wall_hit_y;
	data->rays[i].distance = h_dis;
	data->rays[i].was_hit_vertical = 0;
}
