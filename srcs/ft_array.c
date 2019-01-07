/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:32:31 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/04 18:24:15 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**compte les colonnes constituees uniquement de point
*/

static int		ft_count_column(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] == '.')
	{
		if ((i == 15 || i == 16 || i == 17) && buf[i] == '.')
		{
			j++;
			i = j - 5;
		}
		i += 5;
	}
	return (j);
}

/*
**compte les lignes constituees uniquement de point
*/

static int		ft_count_line(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] != '#')
	{
		if (buf[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

/*
**place le tetra en haut a gauche
*/

char			*ft_swap(char *buf, char index)
{
	int i;
	int c;
	int l;

	i = 0;
	c = ft_count_column(buf);
	l = ft_count_line(buf);
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			buf[i] = '.';
			buf[i - c - (5 * l)] = index;
		}
		i++;
	}
	buf[20] = '\0';
	return (buf);
}
