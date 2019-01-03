/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:51:10 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/03 18:10:10 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Supprime le tetra et renvoie la position de placement
*/

size_t	ft_deletetetra(char c, char *tab)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (tab[j] != c)
		j++;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			tab[i] = '.';
		i++;
	}
	return (j);
}
