/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:09:35 by artprevo          #+#    #+#             */
/*   Updated: 2019/01/07 18:20:40 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 21

typedef	struct	s_fill
{
	char			*content;
	char			index;
	size_t			x;
	struct s_fill	*next;
	struct s_fill	*prev;
}				t_fill;

int				main(int ac, char **av);
char			*ft_swap(char *buf, char index);
t_fill			*ft_valid_file(int fd);
t_fill			*ft_listnew(char index, char *content);
void			ft_listrev(t_fill **begin);
void			ft_listadd(t_fill **begin, t_fill *new, char c);
size_t			ft_listlen(t_fill *list);
char			*ft_init(size_t n);
size_t			ft_count(size_t n);
int				ft_place(char *tab, t_fill *new, size_t n, size_t i);
char			*ft_cutstr(char *p, int i);
size_t			ft_deletetetra(char c, char *tab);
void			ft_fill(char *tab, t_fill *new, size_t j, size_t n);
int				ft_check(char *tab, t_fill *new, size_t j, size_t n);
int				ft_countz(char *buf, size_t y);
void			ft_freelst(t_fill **list);
int				ft_checkplace(char *tab, char *buf, size_t y, int i);
int				ft_countx(char *buf, size_t y);
int				ft_countz(char *buf, size_t y);
int				ft_fillplace(char *tab, t_fill *list, size_t y, int i);

#endif
