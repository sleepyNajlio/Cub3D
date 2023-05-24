/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiallize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:45:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/24 05:45:29 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_player(t_player *player, t_parse *parse)
{
	player->x = parse->player_x * CELL_SIZE + CELL_SIZE / 2;
	player->y = parse->player_y * CELL_SIZE + CELL_SIZE / 2;
	if (parse->player_dir == 'N')
		player->angle = M_PI * 1.5;
	else if (parse->player_dir == 'S')
		player->angle = M_PI_2;
	else if (parse->player_dir == 'E')
		player->angle = 0;
	else if (parse->player_dir == 'W')
		player->angle = M_PI;
}

void	init_rays(t_data *data)
{
	int	i;

	i = 0;
	data->rays = malloc((data->parse->map_width * CELL_SIZE) * sizeof(t_ray));
	while (i < data->parse->map_width)
	{
		data->rays[i].fov_angle = 60 * (M_PI / 180);
		data->rays[i].num_rays = data->parse->map_width * CELL_SIZE;
		data->rays[i].ray_angle = 0;
		i++;
	}
}

void	game_init(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->player = (t_player *)malloc(sizeof(t_player));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->parse->map_width * CELL_SIZE, \
			data->parse->map_height * CELL_SIZE, "cub3d");
	init_player(data->player, data->parse);
	init_rays(data);
	main_draw(data);
}
