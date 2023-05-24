/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:53:58 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/24 05:15:35 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
		ray_angle += data->rays->fov_angle / data->rays->num_rays;
		i++;
	}
}