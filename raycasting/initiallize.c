/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiallize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:45:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/26 08:14:32 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_player(t_player *player, t_parse *parse)
{
	player->x = parse->player_x * parse->map_scale + parse->map_scale / 2;
	player->y = parse->player_y * parse->map_scale + parse->map_scale / 2;
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
		data->rays[i].distance = 0;
		i++;
	}
}

void	game_init(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->player = (t_player *)malloc(sizeof(t_player));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	init_player(data->player, data->parse);
	init_rays(data);
	main_draw(data);
}
