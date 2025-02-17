/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:46:45 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 16:53:02 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_pile
{
	int	nbr;
	int	*pilea;
	int	*pileb;
	int	size_a;
	int	size_b;
	int	error;
}		t_pile;

void	s(t_pile *p, char o);
void	pp(t_pile *p, char o);
void	rr(t_pile *p, char o);
void	r(t_pile *p, char o);
void	resolve(t_pile *p);
int		ft_atoi(const char *ts, t_pile *p);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_my_strchr(char *s, char c);
int		create_tab(t_pile *p, int ac, char **av);
int		verif(char **av, int ac, t_pile *p);
void	mini_calloc(t_pile *p);
void	resolve2(t_pile *p);
void	trie100(t_pile *p, int kop);
int		chunk(t_pile *p, int y);
int		rchunk(t_pile *p, int y, int c);
void	ft_preve(t_pile *p);
void	ft_last(t_pile *p, int c);
int		ft_gain_line(t_pile *p, int i, int c, int x);
void	ft_pr(t_pile *p, int y, int c);
void	ft_p(t_pile *p, int y, int c);
int		check_valid(char **av);
int		ft_check_valid(int ac, char **av);

#endif
