#include "cub3d.h"

int	check_wall(t_parse *parse, float x, float y)
{

	int x1;
	int y1;
	int x2;
	int y2;
	
	x1 = floor((x + (CELL_SIZE / 3)) / CELL_SIZE );
	y1 = floor((y + (CELL_SIZE / 3)) / CELL_SIZE);
	x2 = floor((x - (CELL_SIZE / 3)) / CELL_SIZE );
	y2 = floor((y - (CELL_SIZE / 3)) / CELL_SIZE);
	if (parse->map[y1][x1] == '1' || parse->map[y2][x2] == '1')
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

void rot_right(t_data *data)
{
	data->player->angle += P_ROT_SPEED;
	if (data->player->angle > 2 * M_PI)
		data->player->angle -= 2 * M_PI;
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

void rot_left(t_data *data)
{
	data->player->angle -= P_ROT_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 2 * M_PI;
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	
	// printf("keycode: %d\n", keycode);
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
	if (keycode == KEY_RIGHT)
		rot_right(data);
	return (0);
}