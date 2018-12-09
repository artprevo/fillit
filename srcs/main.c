/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:59:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/09 18:15:24 by artprevo         ###   ########.fr       */
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

	list = NULL;
	i = 0;
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
			ft_listadd(&list, ft_listnew(c, buf));
			c++;
		}
		while (list)
		{
			printf("index=%c\n", list->index);
			list = list->next;
			i++;
		}
		printf("i=%d\n", i);
	}
	return (0);
}
