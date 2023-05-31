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

unsigned int	my_mlx_texture(t_data *d, int x, int y, int i)
{
	char	*dst;

	my_get_data_addr(d, i);
	dst = d->img->addr + (y * d->img->line_length + x * (d->img->bits_per_pixel / 8));
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
		data->rays[i].end = SCREEN_HEIGHT ;

	// draw_line(data->img, i , data->rays[i].start, i, data->rays[i].end, RED);
	int off_x = 0;
	int off_y = 0;
	int y = data->rays[i].start;
	if (data->rays[i].was_hit_vertical)
		off_x = (int)data->rays[i].wall_y % data->parse->cell_size;
	else
		off_x = (int)data->rays[i].wall_x % data->parse->cell_size;

	while(y < data->rays[i].end)
	{
		off_y = (y +(w_h / 2) - (SCREEN_HEIGHT / 2)) * ((float)data->parse->cell_size / w_h);
		my_mlx_pixel_put(data->img, i, y, my_mlx_texture(data, off_x, off_y, i));
		y++;
	}



	// if (data->rays[i].ray_angle > M_PI * 1.5)
	// {
	// 	if (data->rays[i].was_hit_vertical)
	// 		draw_line(data->img, i , start, i, end, RED);
	// 	else
	// 		draw_line(data->img, i , start, i, end, WHITE);
	// }
	// else if (data->rays[i].ray_angle < M_PI_2)
	// {
	// 	if (data->rays[i].was_hit_vertical)
	// 		draw_line(data->img, i , start, i, end, RED);
	// 	else
	// 		draw_line(data->img, i , start, i, end, GREEN);
	// }
	// else if (data->rays[i].ray_angle < M_PI && data->rays[i].ray_angle > M_PI_2)
	// {
	// 	if (data->rays[i].was_hit_vertical)
	// 		draw_line(data->img, i , start, i, end, BLUE);
	// 	else
	// 		draw_line(data->img, i , start, i, end, GREEN);
	// }
	// else
	// {
	// 	if (data->rays[i].was_hit_vertical)
	// 		draw_line(data->img, i , start, i, end, BLUE);
	// 	else
	// 		draw_line(data->img, i , start, i, end, WHITE);
	// }

}