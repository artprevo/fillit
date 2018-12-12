/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/12 18:38:35 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_count(size_t n)
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

char	*ft_init(size_t n)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	n = ft_count(n * 4);
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
