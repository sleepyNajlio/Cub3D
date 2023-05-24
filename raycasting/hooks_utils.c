/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:29:17 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/24 05:11:31 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	draw_again(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	main_draw(data);
	return (1);
}

int	check_wall(t_parse *parse, double x, double y)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = floor((x + (CELL_SIZE / 3)) / CELL_SIZE);
	y1 = floor((y + (CELL_SIZE / 3)) / CELL_SIZE);
	x2 = floor((x - (CELL_SIZE / 3)) / CELL_SIZE);
	y2 = floor((y - (CELL_SIZE / 3)) / CELL_SIZE);
	if (parse->map[y1][x1] == '1' || parse->map[y2][x2] == '1')
		return (1);
	return (0);
}
