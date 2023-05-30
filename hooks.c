/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:54:37 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/29 22:44:06 by fel-fil          ###   ########.fr       */
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

int	key_pressed(int keycode, t_data *data)
{
	(void)data;
	// printf("key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		data->player->up = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		data->player->down = 1;
	if (keycode == KEY_A)
		data->player->left = 1;
	if (keycode == KEY_D)
		data->player->right = 1;
	if (keycode == KEY_LEFT)
		data->player->r_left = 1;
	if (keycode == KEY_RIGHT)
		data->player->r_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	(void)data;
	// printf("key released: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		data->player->up = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		data->player->down = 0;
	if (keycode == KEY_A)
		data->player->left = 0;
	if (keycode == KEY_D)
		data->player->right = 0;
	if (keycode == KEY_LEFT)
		data->player->r_left = 0;
	if (keycode == KEY_RIGHT)
		data->player->r_right = 0;
	return (0);
}

void	move(t_data *data)
{
	if (data->player->up)
		move_up(data);
	if (data->player->down)
		move_down(data);
	if (data->player->left)
		move_left(data);
	if (data->player->right)
		move_right(data);
	if (data->player->r_left)
		data->player->angle -= P_ROT_SPEED;
	if (data->player->r_right)
		data->player->angle += P_ROT_SPEED;
}
