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
