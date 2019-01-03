/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:06 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/03 16:10:36 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_fill	*list;
	char	*p;
	int 	fd;
	size_t	i;

	if (ac != 2 || (fd = open(av[1], O_RDWR)) == -1)
	{
		ft_putstr("usage : ./fillit valid_file\n");
		return (0);
	}
	if (!(list = ft_valid_file(fd)))
		return (0);
	i = ft_count(ft_listlen(list) * 4);
	p = ft_init(i);
	while ((ft_place(p, list, i)) == 0)
	{
		i++;
		free(p);
		p = ft_init(i);
	}
	printf("tab = \n%s\n", p);
	return (0);
}
