/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 16:34:54 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	update(t_data *data)
{
	mlx_hook(data->win, 02, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 03, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	move(data);
	draw_again(data);
	return (0);
}

void	game_init(t_data *data)
{
	data->win_w = data->parse->map_width * CELL_SIZE;
	data->win_h = data->parse->map_height * CELL_SIZE;
	data->img = (t_img *)malloc(sizeof(t_img));
	data->player = (t_player *)malloc(sizeof(t_player));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	init_player(data->player, data->parse);
	init_rays(data);
	init_textures(data);
	main_draw(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	first_check(ac, av);
	data->parse = parsing(av[1]);
	game_init(data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
	free_struct(data->parse);
	return (0);
}
