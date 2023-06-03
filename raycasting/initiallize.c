/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiallize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:45:46 by fel-fil           #+#    #+#             */
/*   Updated: 2023/06/03 16:37:37 by fel-fil          ###   ########.fr       */
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
	player->down = 0;
	player->up = 0;
	player->right = 0;
	player->left = 0;
	player->r_right = 0;
	player->r_left = 0;
}

void	init_rays2(t_data *data, int i)
{
	data->rays[i].nxt_horz_x_inter = 0;
	data->rays[i].nxt_ver_x_inter = 0;
	data->rays[i].nxt_horz_y_inter = 0;
	data->rays[i].nxt_ver_y_inter = 0;
	data->rays[i].found_h_wall_hit = 0;
	data->rays[i].found_v_wall_hit = 0;
	data->rays[i].hor_wall_hit_x = 0;
	data->rays[i].ver_wall_hit_x = 0;
	data->rays[i].hor_wall_hit_y = 0;
	data->rays[i].ver_wall_hit_y = 0;
	data->rays[i].wall_x = 0;
	data->rays[i].wall_y = 0;
	data->rays[i].was_hit_vertical = 0;
	data->rays[i].corr_wall_dis = 0;
	data->rays[i].project_plan_dis = 0;
	data->rays[i].wall_strip_height = 0;
	data->rays[i].start = 0;
	data->rays[i].end = 0;
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
		data->rays[i].isfacingdown = 0;
		data->rays[i].isfacingup = 0;
		data->rays[i].isfacingleft = 0;
		data->rays[i].isfacingright = 0;
		data->rays[i].yintercept = 0;
		data->rays[i].xintercept = 0;
		data->rays[i].ystep = 0;
		data->rays[i].xstep = 0;
		init_rays2(data, i);
		i++;
	}
}

void	xpm_to_img(t_data *data, t_text *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(data->mlx, path, &txt->txt_w, &txt->txt_h);
	if (!txt->img)
	{
		write(2, "error xpm\n", 10);
		exit(1);
	}
	txt->addr = mlx_get_data_addr(txt->img,
			&txt->bits_per_pixel, &txt->line_length, &txt->endian);
}

void	init_textures(t_data	*data)
{
	xpm_to_img(data, &data->text[0], data->parse->no);
	xpm_to_img(data, &data->text[1], data->parse->so);
	xpm_to_img(data, &data->text[2], data->parse->ea);
	xpm_to_img(data, &data->text[3], data->parse->we);
}
