#include "raycasting.h"

void	render3dProjection(t_data *data, int i)
{
	data->rays[i].corr_wall_dis = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player->angle);
	data->rays[i].project_plan_dis = (data->win_w / 2) / tan(data->rays[i].fov_angle / 2);
	data->rays[i].wall_strip_height = (data->parse->cell_size / data->rays[i].corr_wall_dis) * data->rays[i].project_plan_dis;

	// draw_rec(data->img, i ,
	// 	(data->win_h / 2) - (data->rays[i].wall_strip_height) / 2 ,
	// 	1, data->rays[i].wall_strip_height);
}