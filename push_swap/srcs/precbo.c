/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precbo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:15:15 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 02:55:47 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_return(t_pile *p)
{
	int	x;
	int	i;

	i = p->size_b;
	x = -2147483648;
	while (i < p->nbr)
	{
		if (p->pileb[i] > x)
			x = p->pileb[i];
		i++;
	}
	return (x);
}

void	ft_preve(t_pile *p)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (p->size_b < p->nbr)
	{
		x = ft_return(p);
		i = p->size_b;
		while (i < p->nbr)
		{
			if (p->pileb[i] == x)
			{
				if (i <= (p->nbr + p->size_b) / 2)
					while (i-- > p->size_b)
						r(p, 'b');
				else
					while (i++ < p->nbr)
						rr(p, 'b');
				pp(p, 'a');
				i = p->nbr;
			}
			i++;
		}
	}
}

void	ft_last(t_pile *p, int c)
{
	while (p->size_a < p->nbr - 1)
	{
		pp(p, 'b');
		while (p->size_a < p->nbr - 1
			&& p->pilea[p->size_a] > p->pilea[p->size_a + 1])
		{
			if (p->pileb[p->size_b] < p->pileb[p->size_b + 1]
				&& p->pileb[p->size_b] > c && p->pileb[p->size_b + 1] >= c)
				s(p, 's');
			else
				s(p, 'a');
		}
	}
}

int	ft_gain_line(t_pile *p, int i, int c, int x)
{
	int	y;

	y = 0;
	while (++i < p->nbr)
	{
		if (p->pilea[i] < c && p->pilea[i] <= x)
		{
			ft_p(p, i, c);
			y += 1;
			i = p->size_a - 1;
		}
		else if (p->pilea[i] < x && p->pilea[i] >= c)
		{
			ft_pr(p, i, c);
			y += 1;
			i = p->size_a - 1;
		}
	}
	return (y);
}

int	ft_check_valid(int ac, char **av)
{
	int		i;
	char	c;

	i = -1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		while (av[1][++i])
		{
			c = av[1][i];
			if ((c < '0' || c > '9') && c != '-' && c != '+' && c != ' ')
				return (0);
			if (c == '-' && ((i > 0 && av[1][i - 1] != ' ') || av[1][i
				+ 1] < '0' || av[1][i + 1] > '9'))
				return (0);
			if (c == '+' && ((i > 0 && av[1][i - 1] != ' ') || av[1][i
				+ 1] < '0' || av[1][i + 1] > '9'))
				return (0);
		}
	}
	else if (ac > 2)
		if (!check_valid(av))
			return (0);
	return (1);
}
