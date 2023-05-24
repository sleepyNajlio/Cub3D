/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:54:37 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/23 10:55:25 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	move_down(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x - cos(data->player->angle) * P_SPEED;
	new_y = data->player->y - sin(data->player->angle) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_again(data);
	}
}

void	move_up(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_again(data);
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle + M_PI / 2) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle + M_PI / 2) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_again(data);
	}
}

void	move_left(t_data *data)
{	
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos(data->player->angle - M_PI / 2) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle - M_PI / 2) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_again(data);
	}
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(data);
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_LEFT)
		rot_left(data);
	if (keycode == KEY_RIGHT)
		rot_right(data);
	return (0);
}
