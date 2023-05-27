/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:17 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/27 14:33:18 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_left(t_data *data)
{
	data->player->angle -= P_ROT_SPEED;
	data->player->angle = standardized_range(data->player->angle);
	draw_again(data);
}

void	rot_right(t_data *data)
{
	data->player->angle += P_ROT_SPEED;
	data->player->angle = standardized_range(data->player->angle);
	draw_again(data);
}

double	standardized_range(double angle)
{
	angle = remainder(angle, 2 * M_PI);
    if (angle < 0) {
        angle = (2 * M_PI) + angle;
    }
    return angle;
}

int	draw_again(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	main_draw(data);
	return (1);
}