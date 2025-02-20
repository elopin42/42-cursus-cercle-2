/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:20:46 by elopin            #+#    #+#             */
/*   Updated: 2025/02/20 00:10:11 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	chunk(t_pile *p, int y)
{
	int	i;
	int	x;
	int	c;
	int	b;

	b = -1;
	i = -1;
	x = 2147483647;
	c = -2147483648;
	while (++b <= y)
	{
		while (++i < p->nbr)
			if (p->pilea[i] < x && p->pilea[i] > c)
				x = p->pilea[i];
		c += 1;
		i = -1;
		c = x;
		x = 2147483647;
	}
	return (c);
}

int	rchunk(t_pile *p, int y, int c)
{
	int	i;
	int	x;
	int	b;

	b = -1;
	i = -1;
	x = 2147483647;
	while (++b <= y)
	{
		while (++i < p->nbr)
			if (p->pilea[i] < x && p->pilea[i] > c)
				x = p->pilea[i];
		c += 1;
		i = -1;
		c = x;
		x = 2147483647;
	}
	return (c);
}

void	ft_p(t_pile *p, int y, int c)
{
	while (y-- > p->size_a)
		r(p, 'a');
	pp(p, 'b');
	r(p, 'b');
	while (p->size_a + 1 < p->nbr - 1
		&& p->pilea[p->size_a] > p->pilea[p->size_a + 1])
	{
		if (p->pileb[p->size_b] < p->pileb[p->size_b + 1]
			&& p->pileb[p->size_b] > c && p->pileb[p->size_b + 1] >= c)
			s(p, 's');
		else
			s(p, 'a');
	}
}

void	ft_pr(t_pile *p, int y, int c)
{
	while (y-- > p->size_a)
		r(p, 'a');
	pp(p, 'b');
	while (p->size_a + 1 < p->nbr - 1
		&& p->pilea[p->size_a] > p->pilea[p->size_a + 1])
	{
		if (p->size_b < p->nbr - 1 && p->pileb[p->size_b] < p->pileb[p->size_b
				+ 1] && p->pileb[p->size_b] > c && p->pileb[p->size_b + 1] >= c)
			s(p, 's');
		else
			s(p, 'a');
	}
}

void	trie100(t_pile *p, int kop)
{
	int	i;
	int	c;
	int	y;
	int	x;
	int	z;

	z = 0;
	c = chunk(p, p->nbr / kop);
	x = rchunk(p, p->nbr / kop, c);
	i = p->size_a - 1;
	y = 0;
	while (z < kop / 2)
	{
		while (y <= p->nbr / kop)
		{
			y += ft_gain_line(p, i, c, x);
			i = p->size_a - 1;
		}
		c = chunk(p, p->nbr / kop);
		x = rchunk(p, p->nbr / kop, c);
		y = 0;
		z++;
	}
	ft_last(p, c);
	ft_preve(p);
}
