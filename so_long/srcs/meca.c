/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:29:20 by elopin            #+#    #+#             */
/*   Updated: 2025/01/22 23:15:50 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

int	c_count(char **map, char f)
{
	int	y;
	int	x;
	int	c;

	c = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == f)
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

void	add_enemie(char ***map)
{
	int		x;
	int		y;
	int		e;
	char	g;

	y = 0;
	x = 0;
	e = 3;
	g = 51;
	while ((*map)[y] && e > 0)
	{
		x = 0;
		while ((*map)[y][x] && e > 0)
		{
			if (((rand() % 12) == 0) && ((*map)[y][x] == '0'))
			{
				(*map)[y][x] = g++;
				e--;
			}
			x++;
		}
		y++;
	}
}

int	getx(char **map)
{
	return (ft_strlen(map[0]));
}

int	gety(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
		y++;
	return (y);
}

void	acces_sorti(char **map, int y, int x, int *c)
{
	if (map[y] == NULL || map[y][x] == '\0' || x < 0 || y < 0)
		return ;
	if (map[y][x] == '1' || (map[y][x] >= 'a' && map[y][x] <= 'z')
		|| map[y][x] == '2')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		(*c)--;
	if (map[y][x] == '0')
		map[y][x] = '2';
	else
		map[y][x] += 32;
	acces_sorti(map, y + 1, x, c);
	acces_sorti(map, y - 1, x, c);
	acces_sorti(map, y, x + 1, c);
	acces_sorti(map, y, x - 1, c);
}
