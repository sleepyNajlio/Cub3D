/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:47:54 by nloutfi           #+#    #+#             */
/*   Updated: 2023/06/03 17:59:59 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	first_check(int ac, char **av)
{
	if (ac != 2)
		errors("Invalid number of arguments");
	if (open(av[1], O_RDONLY) == -1)
		errors("Invalid file");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		errors("Invalid file extension");
}

void	errors(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}
