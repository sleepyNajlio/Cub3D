/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/26 07:02:24 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int ac, char **av)
{
	t_parse	*parse;


	atexit(leak_report);
	first_check(ac, av);
	parse = parsing(av[1]);
	free_struct(parse);
	return (0);
}