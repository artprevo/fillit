/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:59:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/09 20:55:58 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int 			r;
	char 			buf[BUFF_SIZE + 1];
	t_fill			*list;
	char			c;
	int				fd;
	int				i;
	char			*tab;

	list = NULL;
	c = 'A';
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("error opening boloss.\n");
			return (0);
		}
		c = 'A';
		while ((r = read(fd, buf, 21)) > 0)
		{
			buf[r] = '\0';
			ft_listadd(&list, ft_listnew(c, buf), c);
			c++;
		}
		tab = ft_fill(&list);
		printf("tab = \n%s\n", tab);
	}
	return (0);
}
