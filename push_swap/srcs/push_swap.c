/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:03:09 by elopin            #+#    #+#             */
/*   Updated: 2025/02/19 19:24:25 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	check_trie(t_pile *p);

int	main(int ac, char **av)
{
	struct t_pile	p;

	if (ac < 2 || av[1][0] == '\0' || !(verif(av, ac, &p)))
		return (0);
	if (p.nbr > 1 && check_trie(&p))
	{
		if (p.nbr == 3 || p.nbr == 2)
			resolve(&p);
		else if (p.nbr <= 5)
			resolve2(&p);
		else if (p.nbr <= 100)
			trie100(&p, 5);
		else
			trie100(&p, 11);
	}
	return (free(p.pilea), free(p.pileb), 0);
}

int	check_trie(t_pile *p)
{
	int	i;

	i = p->size_a;
	while (++i < -p->nbr - 1)
		if (p->pilea[i - 1] > p->pilea[i])
			return (1);
	return (0);
}
