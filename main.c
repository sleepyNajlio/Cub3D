/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/05/23 10:53:17 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	first_check(ac, av);
	data->parse = parsing(av[1]);
	game_init(data);
	mlx_hook(data->win, 02, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	free_struct(data->parse);
	return (0);
}
