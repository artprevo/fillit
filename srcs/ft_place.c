/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:33:41 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/07 17:58:24 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkplace(char *tab, char *buf, size_t y, int i)
{
	int x;
	int z;

	x = ft_countx(buf, y);
	z = 0;
	if (y > 0)
		z = ft_countz(buf, y);
	while (x != 0)
	{
		while (z != 0)
		{
			if (tab[i] == '\n')
				return (0);
			i++;
			z--;
		}
		if (tab[i] != '.')
			return (0);
		i++;
		x--;
	}
	return (i);
}

int		ft_fillplace(char *tab, t_fill *list, size_t y, int i)
{
	int		x;
	int		z;
	char	*buf;
	char	c;

	c = list->index;
	buf = list->content;
	x = ft_countx(buf, y);
	z = 0;
	if (y > 0)
		z = ft_countz(buf, y);
	while (x != 0)
	{
		while (z != 0)
		{
			i++;
			z--;
		}
		tab[i++] = c;
		x--;
	}
	return (i);
}
