#include "cub3d.h"

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
		// move_up(data);
	if (keycode == KEY_S)
		// move_down(data);
	if (keycode == KEY_A)
		// move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	return (0);
}