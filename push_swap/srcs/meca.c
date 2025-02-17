/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:45:42 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 01:21:54 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s(t_pile *p, char o)
{
	int	tmp;

	tmp = 0;
	if (o == 'a' || o == 's')
	{
		tmp = p->pilea[p->size_a];
		p->pilea[p->size_a] = p->pilea[p->size_a + 1];
		p->pilea[p->size_a + 1] = tmp;
	}
	tmp = 0;
	if (o == 'b' || o == 's')
	{
		tmp = p->pileb[p->size_b];
		p->pileb[p->size_b] = p->pileb[p->size_b + 1];
		p->pileb[p->size_b + 1] = tmp;
	}
	ft_printf("s%c\n", o);
}

void	pp(t_pile *p, char o)
{
	if (o == 'a')
	{
		p->size_a -= 1;
		p->pilea[p->size_a] = p->pileb[p->size_b];
		p->pileb[p->size_b] = 0;
		p->size_b += 1;
	}
	else if (o == 'b')
	{
		p->size_b -= 1;
		p->pileb[p->size_b] = p->pilea[p->size_a];
		p->pilea[p->size_a] = 0;
		p->size_a += 1;
	}
	ft_printf("p%c\n", o);
}

void	rr(t_pile *p, char o)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = p->nbr;
	if (o == 'a' || o == 'r')
	{
		tmp = p->pilea[p->nbr - 1];
		while (--i > p->size_a)
			p->pilea[i] = p->pilea[i - 1];
		p->pilea[p->size_a] = tmp;
	}
	i = p->nbr;
	if (o == 'b' || o == 'r')
	{
		tmp = p->pileb[p->nbr - 1];
		while (--i > p->size_b)
			p->pileb[i] = p->pileb[i - 1];
		p->pileb[p->size_b] = tmp;
	}
	ft_printf("rr%c\n", o);
}

void	r(t_pile *p, char o)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	if (o == 'a' || o == 'r')
	{
		i = p->size_a;
		tmp = p->pilea[p->size_a];
		while (i < p->nbr - 1)
		{
			p->pilea[i] = p->pilea[i + 1];
			i++;
		}
		p->pilea[p->nbr - 1] = tmp;
	}
	if (o == 'b' || o == 'r')
	{
		i = p->size_b - 1;
		tmp = p->pileb[p->size_b];
		while (++i < p->nbr - 1)
			p->pileb[i] = p->pileb[i + 1];
		p->pileb[p->nbr - 1] = tmp;
	}
	ft_printf("r%c\n", o);
}
