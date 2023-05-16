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




void  draw_rays(t_data *data)
{
	float atan;
	int dof;
	// int mp;
	int mx;
	int my;

	dof = 0;
	data->rays.angle = data->player->angle;
	atan = -1 / tan(data->rays.angle);
	printf("ra = %f \n", data->rays.angle);
	// checkin horizontal lines
	if (data->rays.angle < M_PI) // looking up
	{
		printf("hanaaa \n");
		data->rays.ry = (((int)data->player->y / CELL_SIZE) * CELL_SIZE )- 0.0001;
		data->rays.rx = (data->player->y - data->rays.ry) * atan + data->player->x;
		data->rays.yo = - CELL_SIZE;
		data->rays.xo = -data->rays.yo * atan;
		// printf("rx = %f, ry = %f\n", data->rays.rx, data->rays.ry);
	}
	// printf("%f  %f\n", data->rays.ry, data->rays.rx);
	if (data->rays.angle > M_PI) // looking down
	{
		printf("hanaaa1  \n");
		data->rays.ry = (((int)data->player->y / CELL_SIZE) * CELL_SIZE) + CELL_SIZE;
		data->rays.rx = (data->player->y - data->rays.ry) * atan + data->player->x;
		data->rays.yo = CELL_SIZE;
		data->rays.xo = -data->rays.yo * atan;
	}
	if (data->rays.angle == 0 || data->rays.angle == M_PI) // looking straight left or right
	{
		data->rays.rx = data->player->x;
		data->rays.ry = data->player->y;
		// data->rays.xo = 0;
		// data->rays.yo = 0;
		dof = 8;
	}
	printf("rx = %f, ry = %f\n", data->rays.rx, data->rays.ry);
	while (dof < 8)
	{
		mx = data->rays.rx / CELL_SIZE;
		my = data->rays.ry / CELL_SIZE;
		printf("%d  %d \n", mx, my);
		// mp = ((data->rays.rx / CELL_SIZE) * data->parse->map_width) + (data->rays.ry / CELL_SIZE);
		if ( mx < 0 || my < 0 || mx > data->parse->map_height || my > data->parse->map_width || data->parse->map[my][mx] == '1')
			dof = 8;
		else
		{
			data->rays.rx += data->rays.xo;
			data->rays.ry += data->rays.yo;
			dof++;
		}
	}
	draw_line(data->img, data->player->x, data->player->y, data->rays.rx, data->rays.ry, GREEN);
}

void	draw_player(t_data *data)
{

	float x;
	float y;
	float angle;

	x = data->player->x;
	y = data->player->y;
	angle = data->player->angle;
	// printf("ra = %f \n", angle);
	draw_circle(data->img, x - CELL_SIZE / 2, y - CELL_SIZE / 2, CELL_SIZE / 2, RED);
	draw_line(data->img, x, y, x - cos(angle) * CELL_SIZE / 2, y - sin(angle) * CELL_SIZE / 2, BLUE);
	draw_rays(data);
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
