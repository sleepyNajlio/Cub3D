#include "raycasting.h"

void	facing_dir(t_data *data, int i)
{
	data->rays[i].isfacingdown = (data->rays[i].ray_angle > 0 && data->rays[i].ray_angle < M_PI);
	data->rays[i].isfacingup = !(data->rays[i].isfacingdown);
	data->rays[i].isfacingright = (data->rays[i].ray_angle < M_PI_2 || data->rays[i].ray_angle > (M_PI * 1.5));
	data->rays[i].isfacingleft = !(data->rays[i].isfacingright);
}

void	x_y_first_inter(t_data *data, int i)
{
	data->rays[i].yintercept = floor(data->player->y / CELL_SIZE) * CELL_SIZE;
	if (data->rays[i].isfacingdown)
		data->rays[i].yintercept += CELL_SIZE;

	data->rays[i].xintercept = data->player->x + (data->rays[i].yintercept - data->player->y) / tan(data->rays[i].ray_angle);
}

void	delta_x_y(t_data *data, int i)
{
	data->rays[i].ystep = CELL_SIZE;
	if (data->rays[i].isfacingup)
		data->rays[i].ystep *= -1;

	data->rays[i].xstep = CELL_SIZE / tan(data->rays[i].ray_angle);
	if (data->rays[i].isfacingleft && data->rays[i].xstep > 0)
		data->rays[i].xstep *= -1;
	if (data->rays[i].isfacingright && data->rays[i].xstep < 0)
		data->rays[i].xstep *= -1;

}

void	stop_inc(t_data *data, int i)
{
	data->rays[i].hor_wall_hit_x = data->rays[i].nxt_horz_x_inter;
	data->rays[i].hor_wall_hit_y = data->rays[i].nxt_horz_y_inter;
}

void	inc_ray(t_data *data, int i)
{
	data->rays[i].nxt_horz_x_inter += data->rays[i].xstep;
		data->rays[i].nxt_horz_y_inter += data->rays[i].ystep;
}