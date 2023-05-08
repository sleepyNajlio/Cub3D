/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/07 19:07:38 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_parse *parse)
{
	player->x = parse->player_x * CELL_SIZE + CELL_SIZE / 2;
	player->y = parse->player_y * CELL_SIZE + CELL_SIZE / 2;
	if (parse->player_dir == 'N')
		player->angle = PI * 3 / 2;
	else if (parse->player_dir == 'S')
		player->angle = PI / 2;
	else if (parse->player_dir == 'E')
		player->angle = 0;
	else if (parse->player_dir == 'W')
		player->angle = PI;
}

// void print_player(t_player *player)
// {
// 	printf("x: %f\n", player->x);
// 	printf("y: %f\n", player->y);
// 	printf("angle: %f\n", player->angle);
// }

void	game_init(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,data->parse->map_width * CELL_SIZE, data->parse->map_height * CELL_SIZE, "cub3d");
	data->img->img = mlx_new_image(data->mlx, data->parse->map_width * CELL_SIZE, data->parse->map_height * CELL_SIZE);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	data->player = (t_player *)malloc(sizeof(t_player));
	init_player(data->player, data->parse);
	// print_player(data->player);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	first_check(ac, av);
	data->parse = parsing(av[1]);
	game_init(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	free_struct(data->parse);
	return (0);
}