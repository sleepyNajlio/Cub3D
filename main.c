/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:30:33 by nloutfi           #+#    #+#             */
/*   Updated: 2023/04/26 11:00:38 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parse.h"

int	main(int ac, char **av)
{
	t_parse	*parse;


	first_check(ac, av);
	parse = parsing(av[1]);
	free_struct(parse);
	return (0);
}