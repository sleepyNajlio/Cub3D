/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:54:37 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 21:23:09 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x - cos(data->player->angle) * P_SPEED;
	new_y = data->player->y - sin(data->player->angle) * P_SPEED;
	if (has_wall_at(data, new_x, data->player->y) == 0)
		data->player->x = new_x;
	if (has_wall_at(data, data->player->x, new_y) == 0)
		data->player->y = new_y;
}

void	move_up(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle) * P_SPEED;
	if (has_wall_at(data, new_x, data->player->y) == 0)
		data->player->x = new_x;
	if (has_wall_at(data, data->player->x, new_y) == 0)
		data->player->y = new_y;
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle + M_PI / 2) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle + M_PI / 2) * P_SPEED;
	if (has_wall_at(data, new_x, data->player->y) == 0)
		data->player->x = new_x;
	if (has_wall_at(data, data->player->x, new_y) == 0)
		data->player->y = new_y;
}

void	move_left(t_data *data)
{	
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle - M_PI / 2) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle - M_PI / 2) * P_SPEED;
	if (has_wall_at(data, new_x, data->player->y) == 0)
		data->player->x = new_x;
	if (has_wall_at(data, data->player->x, new_y) == 0)
		data->player->y = new_y;
}
