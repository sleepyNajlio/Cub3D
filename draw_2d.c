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

void	draw_line(t_img *img, float x1, float y1, float x2, float y2, int color)
{
	float x;
	float y;
	float dx;
	float dy;
	float step;

	dx = x2 - x1;
	dy = y2 - y1;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	x = x1;
	y = y1;
	while (step--)
	{
		my_mlx_pixel_put(img, x, y, color);
		x += dx;
		y += dy;
	}
}

void	draw_player(t_data *data)
{

	float x;
	float y;
	float angle;
	float size;

	x = data->player->x - CELL_SIZE / 2;
	y = data->player->y - CELL_SIZE / 2;
	angle = data->player->angle;
	size = CELL_SIZE;
	// draw_square(data->img, x + size * cos(angle), y + size * sin(angle), 5, GREEN);
	draw_line(data->img, x  ,y , x + size * cos(angle), y + size * sin(angle), RED);
	draw_square(data->img, x  , y, CELL_SIZE, GREEN);
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
				draw_square(data->img, j * CELL_SIZE, i * CELL_SIZE,CELL_SIZE, WHITE);
			draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, i * CELL_SIZE, BLACK);
			draw_line(data->img, j * CELL_SIZE, i * CELL_SIZE, j * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
			draw_line(data->img, (j + 1) * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
			draw_line(data->img, j * CELL_SIZE, (i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, BLACK);
			j++;
		}
		i++;
	}
	draw_player(data);
	// draw_square(data->img, data->parse->player_x * CELL_SIZE, data->parse->player_y * CELL_SIZE, CELL_SIZE, RED);
}
