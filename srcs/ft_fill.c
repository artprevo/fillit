/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:13 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/09 20:55:59 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_fill(t_fill **begin)
{
	t_fill	*current;
	int		i;
	char	*tab;

	i = 1;
	current = *begin;
	tab = ft_strdup("");
	while (current)
	{
		tab = ft_strnjoin_free(tab, current->content, 21 * i);
		current = current->next;
		i++;
	}
	i = 0;
	return (tab);
}
