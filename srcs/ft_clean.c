/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:32:31 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/11 17:59:11 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_count_column(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		while (buf[i] == '.')
		{
			if ((i == 15 || i == 16 || i == 17 || i = 18:wq
						) && buf[i] == '.')
			{
				j++;
				i = j - 5;
			}
			i += 5;
		}
		i++;
	}
	return (j);
}

static int		ft_count_line(char *buf, index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] != index)
	{
		if (buf[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

static	char	*ft_clean(char *buf)
{
	int		i;
	int		c;
	int		l;
	char	*str;
	char	*tmp;

	i = 21 - (5 * (ft_count_column(buf) + ft_count_line(buf)));
	printf("c = %d // l = %d\n", ft_count_column(buf), ft_count_line(buf));
	str = ft_strnew(i);
	printf("i = %d // str = %s\n", i, str);
	while (buf[i] == '.' || buf[i] == '\n')
	{
		*str = buf[i];
		i++;
		str++;
		printf("str[i] = %c // buf[i] = %c\n", *str, buf[i]);
	}
	while (buf[i])
	{
		if (buf[i] != '.')
		{
			*str = buf[i];
			str++;
			printf("str[i] = %c // buf[i] = %c\n", *str, buf[i]);
		}
		i++;
	}
	return (str);
}

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
			buf[i - c - (5 * l)] = '#';
		}
		i++;
	}
	buf[20] = '\0';
	buf = ft_clean(buf);
	return (buf);
}
