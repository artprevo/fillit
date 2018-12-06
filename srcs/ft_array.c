/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:32:31 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/06 21:26:00 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int		ft_count_column(char *buf)
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

int		ft_count_line(char *buf)
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

char	*ft_swap(char *buf)
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
			buf[i - c - (5 * l)] = '#';
		}
		i++;
	}
	return (buf);
}
