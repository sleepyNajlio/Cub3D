/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:11:22 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/13 10:16:29 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode, t_data *data)
{
	(void)data;
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
	if (keycode == KEY_ESC)
	{
		free_data(data);
		// mlx_destroy_image(data->mlx, data->img->img);
		// mlx_destroy_window(data->mlx, data->win);
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
