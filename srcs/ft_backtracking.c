/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:31:23 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/03 21:41:37 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_backtracking(t_fill *list, char *tab, size_t n)
{
	size_t	i;
	char	c;
	int		k;

	i = 0;
	k = 0;
	while (list)
	{
		if (i >= (n * (n + 1)) - 1)
			return (0);
		i = 0;
		c = list->index;
		while (tab[i] != '.')
			i++;
		if ((ft_checkiterative(tab, list, i, n)) >= 0)
		{
			ft_putstr("PLACE UN TETRA\n");
			ft_fill(tab, list, ft_checkiterative(tab, list, i, n), n);
			list->x = i;
			list = list->next;
		}
		else
		{
			if (list->prev)
			{
				while (ft_checkiterative(tab, list, i, n) == -1)
				{
					list = list->prev;
					c = list->index;
					i = 1 + ft_deletetetra(c, tab);
				}
				ft_fill(tab, list, ft_checkiterative(tab, list, i, n), n);
				list->x = i;
				list = list->next;
			}
			else
				return (0);
		}
	}
	return (1);
}

int	ft_checkiterative(char *tab, t_fill *list, size_t i, size_t n)
{
	while (tab[i])
	{
		while (tab[i] != '.')
			i++;
		if (ft_check(tab, list, i, n) == 1)
			return (i);
		else
			i++;
	}
	return (-1);
}

/*
int		ft_listprev()
{
	if ((ft_checkiterative(tab, list, i, n)) >= 0)
	{
		ft_fill(tab, list, ft_checkiterative(tab, list, i, n), n);
		list->x = i;
		list = list->next;
	}
	else
	{
		if (list->prev)
		{
			list = list->prev;
			c = list->index;
			i = 1 + ft_deletetetra(c, tab);
		}
		else
			return (0);
	}
}
*/
