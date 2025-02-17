/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:23:44 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 01:21:15 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	resolve2_2(t_pile *p);

// pour 3 et 2
void	resolve(t_pile *p)
{
	int	x;
	int	i;

	i = p->size_a - 1;
	x = -2147483648;
	while (++i < p->nbr)
		if (p->pilea[i] > x)
			x = p->pilea[i];
	if (x == p->pilea[p->size_a] && p->nbr - p->size_a > 2)
		r(p, 'a');
	else if (x == p->pilea[p->size_a + 1] && p->nbr - p->size_a > 2)
		rr(p, 'a');
	if (p->pilea[p->size_a] > p->pilea[p->size_a + 1])
		s(p, 'a');
	if (p->nbr == 5)
		pp(p, 'a');
}

void	mini_calloc(t_pile *p)
{
	int	i;

	i = -1;
	while (++i < p->nbr)
	{
		p->pilea[i] = 0;
		p->pileb[i] = 0;
	}
}

// x min et y max 5 et 4
void	resolve2(t_pile *p)
{
	int	i;
	int	a;
	int	y;

	i = 0;
	y = 0;
	a = p->nbr - 3;
	while (a-- > 0)
	{
		i = p->size_a - 1;
		y = p->size_a;
		while (++i < p->nbr)
			if (p->pilea[i] < p->pilea[y])
				y = i;
		if (y <= p->nbr / 2)
			while (y-- > p->size_a)
				r(p, 'a');
		else if (y > p->nbr / 2)
			while (y++ < p->nbr)
				rr(p, 'a');
		pp(p, 'b');
	}
	resolve(p);
	pp(p, 'a');
}
