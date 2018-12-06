/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:59:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/06 21:24:52 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		ft_list(t_fill **file, char index, char *content)
{
	t_fill	*tmp;
	t_fill	*new;
	int c;
	int l;

	tmp = *file;
	if (!(new = malloc(sizeof(*new))))
		return (0);
	new->index = index;
	new->next = NULL;
	new->prev = tmp;
	printf("content1 = \n%s\n", content);
	if (!(new->content = ft_strdup(ft_swap(content))))
		return (0);
	printf("content2 = \n%s\nindex = %c\n", new->content, new->index);
	return (1);
}

int			main(int ac, char **av)
{
	int 			r;
	char 			buf[BUFF_SIZE + 1];
	t_fill			*file;
	char			c;
	int				fd;

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
			if (!(ft_list(&file, c, buf) == 1))
				return (0);
			c++;
		}
	}
	return (0);
}
