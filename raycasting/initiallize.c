/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiallize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:45:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/05/29 22:00:46 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_player(t_player *player, t_parse *parse)
{
	player->x = parse->player_x * parse->cell_size + parse->cell_size / 2;
	player->y = parse->player_y * parse->cell_size + parse->cell_size / 2;
	if (parse->player_dir == 'N')
		player->angle = M_PI * 1.5;
	else if (parse->player_dir == 'S')
		player->angle = M_PI_2;
	else if (parse->player_dir == 'E')
		player->angle = 0;
	else if (parse->player_dir == 'W')
		player->angle = M_PI;
	player->down = 0;
	player->up = 0;
	player->right = 0;
	player->left = 0;
	player->r_right = 0;
	player->r_left = 0;
}

void	init_rays(t_data *data)
{
	int	i;

	i = 0;
	data->rays = malloc(SCREEN_WIDTH * sizeof(t_ray));
	while (i < SCREEN_WIDTH)
	{
		data->rays[i].fov_angle = 60 * (M_PI / 180);
		data->rays[i].num_rays = SCREEN_WIDTH;
		data->rays[i].ray_angle = 0;
		data->rays[i].distance = 0;
		i++;
	}
}

void	game_init(t_data *data)
{
	data->win_w = data->parse->map_width * data->parse->cell_size;
	data->win_h = data->parse->map_height * data->parse->cell_size;
	data->img = (t_img *)malloc(sizeof(t_img));
	data->player = (t_player *)malloc(sizeof(t_player));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	init_player(data->player, data->parse);
	init_rays(data);
	printf("%d %d\n", data->parse->map_width,data->parse->map_height);
	main_draw(data);
}
