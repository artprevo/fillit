/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:27:31 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/02 16:50:18 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_safejoin(char *s1, char *s2)
{
	char	*join;
	char	*tmp;

	tmp = s1;
	if (!s1 || !s2 || !(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(join, s1);
	ft_strcat(join, s2);
	free(tmp);
	return (join);
}

char	*ft_cutstr(char *p, int i)
{
	char	*cut;
	int		j;
	int		x;

	j = i + 20;
	x = 0;
	if (!((cut = ft_strnew(21))))
		return (NULL);
	while (i < j)
		cut[x++] = p[i++];
	cut[x] = '\0';
	return (cut);
}
