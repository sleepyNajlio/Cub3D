#include "raycasting.h"

void	render3dProjection(t_data *data, int i)
{
	data->rays[i].corr_wall_dis = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player->angle);
	data->rays[i].project_plan_dis = (data->win_w / 2) / tan(data->rays[i].fov_angle / 2);
	data->rays[i].wall_strip_height = (data->parse->cell_size / data->rays[i].corr_wall_dis) * data->rays[i].project_plan_dis;
	if (data->rays[i].wall_strip_height >= SCREEN_HEIGHT)
		data->rays[i].wall_strip_height = SCREEN_HEIGHT - 1;
	int start =  (SCREEN_HEIGHT/ 2) - (data->rays[i].wall_strip_height / 2);
	if (start < 0)
		start = 0;

	if (data->rays[i].ray_angle > M_PI * 1.5)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, RED);
		else
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, WHITE);
	}
	else if (data->rays[i].ray_angle < M_PI_2)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, RED);
		else
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, GREEN);
	}
	else if (data->rays[i].ray_angle < M_PI && data->rays[i].ray_angle > M_PI_2)
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, BLUE);
		else
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, GREEN);
	}
	else
	{
		if (data->rays[i].was_hit_vertical)
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, BLUE);
		else
			draw_rectangle(data->img, i , start, 1, data->rays[i].wall_strip_height, WHITE);
	}

	// draw_rectangle(data->img, i ,
	// 	start,
	// 	1, data->rays[i].wall_strip_height, WHITE);
}