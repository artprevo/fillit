/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/04 18:22:38 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**calcule le nb de cote du plus petit carre possible (FONCTIONNEL)
*/

size_t	ft_count(size_t n)
{
	size_t	i;

	i = 1;
	if (n == 1)
		return (1);
	while (i < n)
	{
		i++;
		if (i * i == n)
			return (i);
	}
	return (ft_count(n + 1));
}

/*
**genere le plus petit tableau possible (A BOSSER POUR INCORPORER LE BACKTRACK)
*/

char	*ft_init(size_t n)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_strnew(n * n + n);
	while (tab[i])
	{
		if (i % (n + ((n + 1) * j)) == 0 && (i > (n + 1)))
		{
			tab[i] = '\n';
			j++;
		}
		else if (i == n)
		{
			tab[i] = '\n';
			j++;
		}
		i++;
	}
	return (tab);
}
