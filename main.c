/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/27 14:46:37 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int update(t_data *data)
{
	mlx_hook(data->win, 02, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 03, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	move(data);
	draw_again(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	first_check(ac, av);
	data->parse = parsing(av[1]);
	game_init(data);
	// printf("key: %d\n", 54);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
	free_struct(data->parse);
	return (0);
}
