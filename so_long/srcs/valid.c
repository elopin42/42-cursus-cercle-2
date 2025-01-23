/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:51:44 by elopin            #+#    #+#             */
/*   Updated: 2025/01/22 19:00:54 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_longueur(char **map)
{
	int	i;
	int	b;
	int	c;

	i = 0;
	b = 0;
	c = 0;
	i = ft_strlen(map[1]);
	b = i;
	while (map[c])
	{
		b = ft_strlen(map[c++]);
		if (b != i)
			return (ft_printf("elle ne sont pas toute a lla meme longueur.\n"),
				0);
	}
	return (1);
}

int	check_taille(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		i = ft_strlen(map[y]);
		if (i <= 2)
			return (ft_printf("probleme de taille de map\n"), 0);
		y++;
	}
	if (y <= 2)
		return (0);
	y = 0;
	return (1);
}

int	check_border(char **map)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (0);
	while (map[c])
		c++;
	i = 0;
	while (map[c - 1][i])
		if (map[c - 1][i++] != '1')
			return (0);
	while (--c >= 1)
	{
		if (map[c][0] != '1' || map[c][ft_strlen(map[c]) - 1] != '1')
			return (0);
	}
	return (1);
}

int	valid_map(char **map)
{
	int	c;
	int	y;
	int	x;

	x = 0;
	y = 0;
	pjoueur(map, &x, &y, 'P');
	c = c_count(map, 'C');
	if (!(check_longueur(map)) || !(check_0(map)) || !(check_taille(map)))
		return (ft_printf("error\n"), 0);
	else if (!(check_border(map)))
		return (ft_printf("les bords ne sont pas bon.\n"), 0);
	else if (c_count(map, 'P') != 1 || c_count(map, 'E') != 1)
		return (ft_printf("il y a pas 1 joueur ou 1 sorti.\n"), 0);
	acces_sorti(map, y, x, &c);
	ft_reset_map(map);
	if (c != -1)
		return (ft_printf("sorti ou collectible non accessible\n"), 0);
	else
		return (1);
}

int	swap_case(char *a, char *b, int i)
{
	char	tmp;

	if ((*b) == 'E' && i == 1)
		return (-1);
	else if (((*b) == 'C' && i == 1) || ((*b) == 'P' && i == 0))
	{
		(*b) = (*a);
		(*a) = '0';
		return (1);
	}
	else if (((*b) >= 51 && (*b) <= 53) && i == 1)
	{
		(*a) = '0';
		return (1);
	}
	else if ((*b) != '1')
	{
		tmp = (*a);
		(*a) = (*b);
		(*b) = tmp;
		return (1);
	}
	else if (i == 1)
		return ((ft_printf("oups ya un mur\n"), 0));
	return (0);
}
