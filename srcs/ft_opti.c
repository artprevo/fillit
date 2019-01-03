/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:54:44 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/03 22:43:25 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_checkoptiz(char *tab, t_fill *new, size_t j, size_t n)
{
	size_t	i;

	i = j + 1;
	if (tab[i] == new->index)
	{
		if (tab[i + 1] == new->index)
		{
			if (tab[i - 1] == '.')
			{
				i = i + n + 1;
				if (tab[i] == new->index)
				{
					if (tab[i - 1] == new->index)
					{
						if (tab[i - 2] == '.')
						{
							tab[i] = '.';
							tab[i - 2] = new->index;
							tab[i - n] = '.';
							tab[i - n - 2] = new->index;
						}
					}
				}
			}
		}
	}
}

int	ft_checkoptileft(char *tab, t_fill *new, size_t n)
{
	size_t	i;
	char	c;
	int		k;

	i = n;
	i = 0;
	c = new->index;
	k = 0;
	while (tab[i] != c)
		i++;
	if (i > 0)
	{
		if (tab[i - 1] == '.')
		{
			while (tab[i] == c)
			{
				i++;
				k++;
				if (k == 4)
				{
					ft_placeleft(tab, c);
					return (1);
				}
			}
			while (tab[i] != c)
				i++;
			if (tab[i - 1] == '.')
			{
				while (tab[i] == c)
				{
					i++;
					k++;
					if (k == 4)
					{
						ft_placeleft(tab, c);
						return (1);
					}
				}
				while (tab[i] != c)
					i++;
				if (tab[i - 1] == '.')
				{
					while (tab[i] == c)
					{
						i++;
						k++;
						if (k == 4)
						{
							ft_placeleft(tab, c);
							return (1);
						}
					}
					while (tab[i] != c)
						i++;
					if (tab[i - 1] == '.')
					{
						ft_placeleft(tab, c);
						return (1);
					}
				}
			}
		}
	}
	return (0);
}

void	ft_placeleft(char *tab, char c)
{
	int i;

	i = 0;
	while (tab[i])
	{
		while (tab[i] == c)
		{
			tab[i - 1] = c;
			tab[i] = '.';
			i++;
		}
		i++;
	}
}
