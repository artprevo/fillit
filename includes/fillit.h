/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:09:35 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/06 21:08:13 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 21

typedef struct		s_fill
{
	char			*content;
	char			index;
	struct s_fill	*next;
	struct s_fill	*prev;
}					t_fill;

int		main(int ac, char **av);
char	*ft_swap(char *buf);

#endif
