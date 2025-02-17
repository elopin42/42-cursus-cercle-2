/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_meca.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:54:09 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 03:02:08 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	create_tab(t_pile *p, int ac, char **av);
int	reel_create_tab(t_pile *p, char **av, int ac);
int	verif_double(t_pile *p);

int	verif(char **av, int ac, t_pile *p)
{
	if (!create_tab(p, ac, av))
		return (ft_printf("error\n"), 0);
	if (!ft_check_valid(ac, av))
		return (ft_printf("error\n"), free(p->pilea), free(p->pileb), 0);
	if (!(reel_create_tab(p, av, ac)))
		return (ft_printf("error\n"), free(p->pilea), free(p->pileb), 0);
	if (!(verif_double(p)))
		return (ft_printf("error\n"), free(p->pilea), free(p->pileb), 0);
	return (1);
}

int	make_ac(char *av)
{
	int	i;
	int	b;

	b = 0;
	i = -1;
	while (av[++i])
	{
		if (av[i] >= '0' && av[i] <= '9')
		{
			while (av[i] >= '0' && av[i] <= '9')
				i++;
			b++;
			i--;
		}
		else if (av[i] != ' ' && av[i] != '-' && av[i] != '+')
			return (0);
	}
	return (b);
}

int	create_tab(t_pile *p, int ac, char **av)
{
	if (ac > 2)
		p->nbr = ac - 1;
	else if (ac == 2)
	{
		p->nbr = make_ac(av[1]);
	}
	else
		return (0);
	if (!p->nbr)
		return (0);
	p->pilea = malloc(p->nbr * sizeof(int));
	if (!p->pilea)
		return (0);
	p->pileb = malloc(p->nbr * sizeof(int));
	if (!p->pileb)
		return (free(p->pilea), 0);
	p->size_a = 0;
	p->size_b = p->nbr;
	mini_calloc(p);
	return (1);
}

int	reel_create_tab(t_pile *p, char **av, int ac)
{
	int		i;
	char	*str;
	int		b;

	i = -1;
	b = 0;
	str = NULL;
	if (ac > 2)
		while (++i < p->nbr)
			p->pilea[i] = ft_atoi(av[i + 1]);
	else
	{
		if (av[1][0] == ' ')
			return (0);
		while (av[1][++i] && i < p->nbr)
		{
			str = ft_substr(av[1], b, ft_my_strchr(&av[1][b], ' '));
			if (!str)
				return (0);
			b += ft_my_strchr(&av[1][b], ' ') + 1;
			p->pilea[i] = ft_atoi(str);
			free(str);
		}
	}
	return (1);
}

int	verif_double(t_pile *p)
{
	int	i;
	int	b;

	i = -1;
	b = -1;
	while (++i < p->nbr)
	{
		b = -1;
		while (++b < p->nbr)
			if (p->pilea[i] == p->pilea[b] && i != b)
				return (0);
	}
	return (1);
}
