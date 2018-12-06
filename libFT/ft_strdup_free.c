/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:04:57 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:04 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *content, int r)
{
	char	*tmp;

	tmp = content;
	content = ft_strdup(content + r);
	free(tmp);
	return (content);
}
