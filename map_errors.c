/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:47:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/18 08:26:31 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void first_check(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error; Try : ./Cub3D map_path.cub");
		exit(1);
	}
	if (open(av[1], O_RDONLY) == -1)
	{
		perror("Error");
		exit(1);
	}
	if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
	{
		printf("Error; Invalid map\n");
		exit(1);
	}
}