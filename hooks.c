#include "cub3d.h"

int	check_wall(t_parse *parse, float x, float y)
{

	int x1;
	int y1;
	// int x2;
	// int y2;


	x1 = floor(x  / CELL_SIZE);
	y1 = floor(y / CELL_SIZE);
	// x2 = floor((x + CELL_SIZE) / CELL_SIZE);
	// y2 = floor((y + CELL_SIZE) / CELL_SIZE);
	// printf("x1: %d\n", x1);
	// printf("y1: %d\n", y1);
	// if (x1 < 0 || y1 < 0 ||  x1 >= parse->map_width || y1 >= parse->map_height)
		// return (1);
	// if (x2 < 0 || y2 < 0 ||  x2 >= parse->map_width || y2 >= parse->map_height)
		// return (1);
	if (parse->map[y1][x1] == '1')
		return (1);
	return (0);
}

void move_up(t_data *data)
{
	float new_x;
	float new_y;

	new_x = data->player->x + cos(data->player->angle) * P_SPEED;
	new_y = data->player->y + sin(data->player->angle) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_down(t_data *data)
{
	float new_x;
	float new_y;

	new_x = data->player->x - cos(data->player->angle) * P_SPEED;
	new_y = data->player->y - sin(data->player->angle) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_left(t_data *data)
{
	float new_x;
	float new_y;

	new_x = data->player->x - cos(data->player->angle + M_PI / 2) * P_SPEED;
	new_y = data->player->y - sin(data->player->angle + M_PI / 2) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void move_right(t_data *data)
{
	
	float new_x;
	float new_y;

	new_x = data->player->x - cos(data->player->angle - M_PI / 2) * P_SPEED;
	new_y = data->player->y - sin(data->player->angle - M_PI / 2) * P_SPEED;
	if (check_wall(data->parse, new_x, new_y) == 0)
	{
		data->player->x = new_x;
		data->player->y = new_y;
		draw_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
}

void rot_left(t_data *data)
{
	data->player->angle += P_ROT_SPEED;
	if (data->player->angle > 2 * M_PI)
		data->player->angle -= 2 * M_PI;
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(data);
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_LEFT)
		rot_left(data);
	return (0);
}