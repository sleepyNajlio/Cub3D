/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/26 12:07:54 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_parse *parse, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, parse->map_width * CELL_SIZE, parse->map_height * CELL_SIZE, "cub3d");
	
	
}

int	main(int ac, char **av)
{
	t_parse	*parse;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	first_check(ac, av);
	parse = parsing(av[1]);
	game_init(parse, data);
	mlx_loop(data->mlx);
	free_struct(parse);
	return (0);
}