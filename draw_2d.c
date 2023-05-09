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

void	draw_circle(t_img *img, int x, int y, int radius, int color)
{
	int i;
	int j;

	i = 0;
	while (i < radius * 2)
	{
		j = 0;
		while (j < radius * 2)
		{
			if (sqrt((radius - i) * (radius - i) + (radius - j) * (radius - j)) <= radius)
				my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}


// void	draw_line(t_img *img, float x1, float y1, float x2, float y2, int color)
// {
// 	float x;
// 	float y;
// 	float dx;
// 	float dy;
// 	float step;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
// 	dx /= step;
// 	dy /= step;
// 	x = x1;
// 	y = y1;
// 	while (step--)
// 	{
// 		my_mlx_pixel_put(img, x, y, color);
// 		x += dx;
// 		y += dy;
// 	}
// }

void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	sx = x0 < x1 ? 1 : -1;
	int	dy = abs(y1 - y0);
	int	sy = y0 < y1 ? 1 : -1;
	int	err = (dx > dy ? dx : -dy) / 2;
	int	e2;

	while (1)
	{
		my_mlx_pixel_put(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player(t_data *data)
{

	float x;
	float y;
	float angle;

	x = data->player->x;
	y = data->player->y;
	angle = data->player->angle;
	draw_circle(data->img, x - CELL_SIZE / 2, y - CELL_SIZE / 2, CELL_SIZE / 2, GREEN);
	draw_line(data->img, x, y, x + cos(angle) * CELL_SIZE / 2, y + sin(angle) * CELL_SIZE / 2, RED);
	// draw_square(data->img, x - CELL_SIZE / 4, y - CELL_SIZE / 4, CELL_SIZE / 2, GREEN);
	// draw_square(data->img , x + (size / 2) * cos(angle), y + (size / 2) * sin(angle), 8, RED);
	// draw_line(data->img, x ,y , x + cos(angle) * P_SPEED, y + sin(angle) * P_SPEED, RED);
	// draw_line(data->img, x, y , )
	// draw_square(data->img, x + size * cos(angle), y + size * sin(angle), 5, RED);
	// draw_square(data->img, x + size * cos(angle + PI / 2), y + size * sin(angle + PI / 2), 5, GREEN);
	// draw_square(data->img, x + size * cos(angle - PI / 2), y + size * sin(angle - PI / 2), 5, GREEN);
	// draw_square(data->img, x + size * cos(angle + PI), y + size * sin(angle + PI), 5, GREEN);
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
			{
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE,CELL_SIZE, WHITE);
				draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, i * CELL_SIZE, BLACK);
				draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, j * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
				draw_line(data->img, (j + 1) * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
				draw_line(data->img, j * CELL_SIZE, (i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
			}
			j++;
		}
		i++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	// draw_square(data->img, data->parse->player_x * CELL_SIZE, data->parse->player_y * CELL_SIZE, CELL_SIZE, RED);
}
