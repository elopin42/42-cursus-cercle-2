/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meca2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:33:04 by elopin            #+#    #+#             */
/*   Updated: 2025/01/22 21:11:26 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <time.h>

void	ft_reset_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] >= 'a' && map[y][x] <= 'z')
				map[y][x] -= 32;
			else if (map[y][x] == '2')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	moov_enemie(char ***tmap, void *mlx, void *win)
{
	static char	**map = NULL;
	static int	e = 0;

	srand(time(NULL));
	if (tmap != NULL)
	{
		map = (*tmap);
		e += c_count(map, 51);
		e += c_count(map, 52);
		e += c_count(map, 53);
		return ;
	}
	else
	{
		help_me(e, map);
		if (!(pjoueur(map, NULL, NULL, 'P')))
			mlx_des(win, mlx);
		else
			put_img(mlx, win, map);
	}
}

int	moov_enemie2(void *param)
{
	void			*win;
	void			*mlx;
	static time_t	last_time = 0;
	time_t			current_time;

	current_time = time(NULL);
	win = ((void **)param)[0];
	mlx = ((void **)param)[1];
	if (current_time - last_time >= 2)
	{
		moov_enemie(NULL, mlx, win);
		last_time = current_time;
	}
	return (0);
}

int	check_0(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'E'
				&& map[y][x] != 'P' && map[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
