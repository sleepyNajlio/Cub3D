#include "raycasting.h"

void	my_get_data_addr(t_data *data, int i)
{
	if (!data->rays[i].was_hit_vertical)
	{
		if (data->rays[i].isfacingup)
		{
			data->img->addr = mlx_get_data_addr(data->so_tx, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
				
		}
		else
		{
			data->img->addr = mlx_get_data_addr(data->no_tx, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
		}
	}
	else
	{
		if (data->rays[i].isfacingright)
			data->img->addr = mlx_get_data_addr(data->we_tx, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
		else
		{
			data->img->addr = mlx_get_data_addr(data->ea_tx, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
		}
	}
}




int	tex_id(t_data *data, int i)
{
	
	if (!data->rays[i].was_hit_vertical)
	{
		if (data->rays[i].isfacingup)
			return (1);
		else
			return (0);
	}
	else
	{
		if (data->rays[i].isfacingright)
			return (3);
		else
			return (2);
	}
}

unsigned int	get_pixel(t_text *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	render3dProjection(t_data *data, int i)
{
	data->rays[i].corr_wall_dis = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player->angle);
	data->rays[i].project_plan_dis = (SCREEN_WIDTH / 2) / tan(data->rays[i].fov_angle / 2);
	data->rays[i].wall_strip_height = (data->parse->cell_size / data->rays[i].corr_wall_dis) * data->rays[i].project_plan_dis;
	int w_h = (int)data->rays[i].wall_strip_height;
	// if (w_h >= SCREEN_HEIGHT)
	// 	w_h = SCREEN_HEIGHT -1 ;

	data->rays[i].start =  (SCREEN_HEIGHT/ 2) - (w_h / 2);
	if (data->rays[i].start < 0)
		data->rays[i].start = 0;

	data->rays[i].end =(SCREEN_HEIGHT/ 2) + (w_h / 2);;
	if (data->rays[i].end > SCREEN_HEIGHT)
		data->rays[i].end = SCREEN_HEIGHT  -1;

	int off_x = 0;
	int off_y = 0;
	int y = data->rays[i].start;
	if (data->rays[i].was_hit_vertical)
		off_x = (int)data->rays[i].wall_y % data->parse->cell_size;
	else
		off_x = (int)data->rays[i].wall_x % data->parse->cell_size;


	int id = tex_id(data, i);
	while(y < data->rays[i].end)
	{
		off_y = (y +((float)w_h / (float)2) - (SCREEN_HEIGHT / 2)) * ((float)data->text[id].txt_h / (float)w_h);

		my_mlx_pixel_put(data->img, i, y, get_pixel(&data->text[id], off_x, off_y));
		y++;
	}
}