#include "raycasting.h"

void	render3dProjection(t_data *data, int i)
{
	data->rays[i].corr_wall_dis = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player->angle);
	data->rays[i].project_plan_dis = (SCREEN_WIDTH / 2) / tan(data->rays[i].fov_angle / 2);
	data->rays[i].wall_strip_height = (data->parse->cell_size / data->rays[i].corr_wall_dis) * data->rays[i].project_plan_dis;
	int w_h = (int)data->rays[i].wall_strip_height;
	if (w_h >= SCREEN_HEIGHT)
		w_h = SCREEN_HEIGHT ;
	int start =  (SCREEN_HEIGHT/ 2) - (w_h / 2);
	if (start < 0)
		start = 0;

	if (data->rays[i].ray_angle > M_PI * 1.5)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, w_h, RED);
		else
			draw_rectangle(data->img, i , start, 1, w_h, WHITE);
	}
	else if (data->rays[i].ray_angle < M_PI_2)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, w_h, RED);
		else
			draw_rectangle(data->img, i , start, 1, w_h, GREEN);
	}
	else if (data->rays[i].ray_angle < M_PI && data->rays[i].ray_angle > M_PI_2)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, w_h, BLUE);
		else
			draw_rectangle(data->img, i , start, 1, w_h, GREEN);
	}
	else
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, w_h, BLUE);
		else
			draw_rectangle(data->img, i , start, 1, w_h, WHITE);
	}

	// draw_rectangle(data->img, i ,
	// 	start,
	// 	1, data->rays[i].wall_strip_height, WHITE);
}