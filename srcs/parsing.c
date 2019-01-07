/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:18:44 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/07 12:47:44 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_find_t1(char *p, int i)
{
	if (p[i + 5] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 5] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 11] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 3] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 5] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 2] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 5] == '#')
		return (1);
	else
		return (0);
}

static int	ft_find_t5(char *p, int i)
{
	if (p[i + 10] == '#' && p[i + 15] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 11] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 7] == '#')
		return (1);
	else if (p[i + 3] == '#' && p[i + 4] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 9] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 6] == '#')
		return (1);
	else if (p[i + 6] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 4] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 9] == '#' && p[i + 10] == '#')
		return (1);
	else if (p[i + 10] == '#' && p[i + 11] == '#')
		return (1);
	else
		return (0);
}

static int	ft_valid_tetra(char *p, int i)
{
	while (p[i])
	{
		while (p[i] != '#')
		{
			if (p[i] == '\0')
				return (0);
			i++;
		}
		if (p[i + 1] == '#' && ft_find_t1(p, i))
			return (1);
		else if (p[i + 5] == '#' && ft_find_t5(p, i))
			return (1);
		else
			return (0);
		while (p[i])
		{
			if (p[i] == '\n' && p[i + 1] == ('\n' || '\0'))
				break ;
			if (p[i] == '\0')
				return (0);
			i++;
		}
	}
	return (0);
}

static int	ft_valid_block(char *p, int line, int count)
{
	int i;

	i = 0;
	while (p[i])
	{
		if (p[i] != '.' && p[i] != '\n' && p[i] != '#' && p[i] != '\0')
			return (0);
		if (p[i] == '\n')
			line++;
		if (line == 5 && p[i - 1] == '\n')
		{
			count = 0;
			line = 0;
		}
		else if ((line == 5 && p[i - 1] != '\n') || \
				(p[i] == '\n' && p[i - 1] == '\n'))
			return (0);
		if (p[i] == '#')
			count++;
		if (line == 4 && count != 4)
			return (0);
		i++;
	}
	return (1);
}

t_fill		*ft_valid_file(int fd)
{
	char	buf[22];
	char	c;
	int		r;
	size_t	len;
	t_fill	*list;

	if (fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	c = 'A';
	while ((r = read(fd, buf, 21)) > 0)
	{
		buf[r] = '\0';
		len = ft_strlen(buf);
		if (!(ft_valid_tetra(buf, 0)) || !(ft_valid_block(buf, 0, 0)))
			return (NULL);
		ft_listadd(&list, ft_listnew(c, buf), c);
		c++;
	}
	if (len == 20)
		return (list);
	return (NULL);
}
