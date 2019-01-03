/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/03 22:40:13 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
   Compte le nombre de caractere sur 1 ligne (appelee 4 fois par ft_fill)
   (FONCTIONNEL)
   */

static int	ft_countx(char *buf, size_t y)
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
   Compte le nombre de point avant le tetra, permet de gerer les tetra de batard
   (FONCTIONNEL ASKIP)
   */

int	ft_countz(char *buf, size_t y)
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
   Check qu'on peut mettre le tetra a partir d'un point donne j du tableau
   (FONCTIONNEL ASKIP)
   */

int	ft_check(char *tab, t_fill *new, size_t j, size_t n)
{
	int		y;
	int		x;
	int		i;
	char	*buf;
	int		z;

	z = 0;
	y = 0;
	buf = new->content;
	while (y != 4)
	{
		i = y + (n * y) + j;
		x = ft_countx(buf, y);
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
		y++;
	}
	return (1);
}

/*
   Remplit le tableau avec le tetra a partir d'un point donne j
   (FONCTIONNEL ASKIP)
   */

void	ft_fill(char *tab, t_fill *new, size_t j, size_t n)
{
	char	*buf;
	size_t	i;
	int		x;
	size_t	y;
	char	index;
	int		z;

	y = 0;
	z = 0;
	buf = new->content;
	index = new->index;
	while (y != 4)
	{
		i = y + (n * y) + j;
		x = ft_countx(buf, y);
		z = ft_countz(buf, y);
		while (x != 0)
		{
			while (z != 0)
			{
				i++;
				z--;
			}
			tab[i] = index;
			i++;
			x--;
		}
		y++;
	}
}

/* 
   Fonction qui articule le tout, et premiere tentative de backtracking
   (BACKTRACK A BOSSER)
   */
int		ft_place(char *tab, t_fill *new, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (new && tab[i])
	{
		while (tab[i] != '.' && tab[i])
			i++;
		if (ft_check(tab, new, i, n) == 1)
		{
			ft_fill(tab, new, i, n);
			ft_checkoptiz(tab, new, i, n);
			new = new->next;
			i = 0;
		}
		else
			i++;
		if (i >= (n * (n + 1)) - 1)
		{
			if (new->prev && k <= n * n * n * n * n)
			{	
				new = new->prev;
				i = 1 + ft_deletetetra(new->index, tab);
				k++;
			}
			else
				return (0);
		}
	}
	return (1);
}
