#include "cub3d.h"

int key_hook(int keycode, t_data *data)
{
	(void)data;
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_data *data;

	(void)ac;
	(void)av;
	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 480, "Hello world!");
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);

}