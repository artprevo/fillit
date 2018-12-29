/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:33:02 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/29 16:51:26 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fill		*ft_listnew(char index, char *content)
{
	t_fill	*new;
	t_fill	*tmp;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	if (new == NULL)
		new->content = NULL;
	else if (!(new->content = ft_strdup(ft_swap(content, index))))
		return (NULL);
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	printf("content = \n%s\nindex = %c\n", new->content, new->index);
	return (new);
}

void		ft_listrev(t_fill **begin)
{
	t_fill *current;
	t_fill *tmp1;
	t_fill *tmp2;

	current = *begin;
	tmp1 = NULL;
	tmp2 = NULL;
	while (current)
	{
		tmp1 = current;
		current = current->next;
		tmp1->next = tmp2;
		tmp1->prev = current;
		tmp2 = tmp1;
	}
	*begin = tmp1;
}

void		ft_listadd(t_fill **begin, t_fill *new, char c)
{
	t_fill	*tmp;

	if (c == 'A')
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}

size_t		ft_listlen(t_fill *list)
{
	size_t	i;

	i = 1;
	while(list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void		ft_listiter(t_fill **begin, char *(*f)(char *s))
{
	t_fill *current;

	current = *begin;
	while (current)
	{
		current->content = f(current->content);
		current = current->next;
	}
}
