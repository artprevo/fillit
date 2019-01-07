/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/07 18:04:01 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**Compte le nombre de caractere sur 1 ligne (appelee 4 fois par ft_fill)
**(FONCTIONNEL)
*/

int			ft_countx(char *buf, size_t y)
{
	size_t	i;
	size_t	x;

	x = 0;
	i = y * 5;
	while (buf[i] == '.')
		i++;
	while (buf[i] != '.' && buf[i] != '\n')
	{
		x++;
		i++;
	}
	return (x);
}

/*
**Compte le nombre de point avant le tetra, permet de gerer les tetra de batard
**(FONCTIONNEL ASKIP)
*/

int			ft_countz(char *buf, size_t y)
{
	size_t	i;
	size_t	z;

	z = 0;
	i = y * 5;
	while (buf[i] == '.')
	{
		z++;
		i++;
	}
	return (z);
}

/*
**Check qu'on peut mettre le tetra a partir d'un point donne j du tableau
**(FONCTIONNEL ASKIP)
*/

int			ft_check(char *tab, t_fill *new, size_t j, size_t n)
{
	size_t	y;
	int		k;
	int		i;
	char	*buf;

	y = 0;
	buf = new->content;
	while (y != 4)
	{
		if (ft_countz(buf, 0) > 0 && y == 1)
			j = j - ft_countz(buf, 0);
		i = y + (n * y) + j;
		k = ft_checkplace(tab, buf, y, i);
		if (k == 0)
			return (0);
		i = k;
		y++;
	}
	return (1);
}

/*
**Remplit le tableau avec le tetra a partir d'un point donne j
**(FONCTIONNEL ASKIP)
*/

void		ft_fill(char *tab, t_fill *new, size_t j, size_t n)
{
	size_t	i;
	size_t	k;
	int		y;
	char	*buf;

	buf = new->content;
	y = 0;
	while (y != 4)
	{
		if (ft_countz(buf, 0) > 0 && y == 1)
			j = j - ft_countz(buf, 0);
		i = y + (n * y) + j;
		k = ft_fillplace(tab, new, y, i);
		i = k;
		y++;
	}
}

/*
**Fonction qui articule le tout, et premiere tentative de backtracking
**(BACKTRACK A BOSSER)
*/

int			ft_place(char *tab, t_fill *new, size_t n, size_t i)
{
	while (new && tab[i])
	{
		while (tab[i] != '.' && tab[i])
			i++;
		if (ft_check(tab, new, i, n) == 1)
		{
			ft_fill(tab, new, i, n);
			new = new->next;
			i = 0;
		}
		else
			i++;
		if (i >= (n * (n + 1)) - 1)
		{
			if (new->prev)
			{
				new = new->prev;
				i = 1 + ft_deletetetra(new->index, tab);
			}
			else
				return (0);
		}
	}
	return (1);
}
