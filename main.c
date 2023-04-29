/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/29 23:52:08 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(t_img *img, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void	draw_map(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->parse->map[i])
	{
		j = 0;
		while (data->parse->map[i][j])
		{
			if (data->parse->map[i][j] == '1')
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE,CELL_SIZE, BLUE);
			else
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE,CELL_SIZE, WHITE);
			j++;
		}
		i++;
	}
	draw_square(data->img, data->parse->player_x * CELL_SIZE, data->parse->player_y * CELL_SIZE, CELL_SIZE, RED);
}

void	game_init(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,data->parse->map_width * CELL_SIZE, data->parse->map_height * CELL_SIZE, "cub3d");
	data->img->img = mlx_new_image(data->mlx, data->parse->map_width * CELL_SIZE, data->parse->map_height * CELL_SIZE);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

void move_up(t_data *data)
{
	
	if (data->parse->map[data->parse->player_y - 1][data->parse->player_x] != '1')
	{
		data->parse->player_y--;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_down(t_data *data)
{
	
	if (data->parse->map[data->parse->player_y + 1][data->parse->player_x] != '1')
	{
		data->parse->player_y++;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_left(t_data *data)
{
	
	if (data->parse->map[data->parse->player_y][data->parse->player_x - 1] != '1')
	{
		data->parse->player_x--;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_right(t_data *data)
{
	
	if (data->parse->map[data->parse->player_y][data->parse->player_x + 1] != '1')
	{
		data->parse->player_x++;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W)
		move_up(data);
	if (keycode == KEY_S)
		move_down(data);
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	return (0);
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