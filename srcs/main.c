/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/02 18:45:44 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_fill	*list;
	char	c;
	char	*p;
	int 	fd;
	size_t	i;

	if (ac != 2 || (fd = open(av[1], O_RDWR)) == -1)
	{
		ft_putstr("usage : ./fillit valid_file\n");
		return (0);
	}
	list = ft_valid_file(fd);
	i = ft_listlen(list);
	p = ft_init(ft_count(i * 4));
	ft_place(p, list, i);
	printf("tab = \n%s\n", p);
	return (0);
}
