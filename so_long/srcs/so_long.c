/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:32:48 by elopin            #+#    #+#             */
/*   Updated: 2025/01/23 16:44:29 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

int	m(int keycode, void *param)
{
	void	*win;
	void	*mlx;
	int		b;
	char	*string;

	string = " <-- voici ton nombre de pas";
	win = ((void **)param)[0];
	mlx = ((void **)param)[1];
	b = 0;
	if (keycode == 119)
		b = swap_map(NULL, 1, win, mlx);
	else if (keycode == 100)
		b = swap_map(NULL, 2, win, mlx);
	else if (keycode == 115)
		b = swap_map(NULL, 3, win, mlx);
	else if (keycode == 97)
		b = swap_map(NULL, 4, win, mlx);
	if ((keycode == 65307) || b < 0)
		return (mlx_des(win, mlx), 0);
	else
		return (string = ft_strjoin(my_ft_itoa(b), string), mlx_string_put(mlx,
				win, 70, 35, 0x000000, string), free(string), 0);
}

int	close_window(void *param)
{
	void	*win;
	void	*mlx;

	win = ((void **)param)[0];
	mlx = ((void **)param)[1];
	return (mlx_des(win, mlx), 0);
}

void	*ft_choose_img(int x, int y, char **map, void *mlx)
{
	void	*img;
	int		width;
	int		height;

	img = NULL;
	if (map[y][x] == '0')
		img = sous_choose_img(y, x, mlx);
	else if (map[y][x] == '1' && ((y + x) % 2) == 0)
		img = mlx_xpm_file_to_image(mlx, "img/ile2.xpm", &width, &height);
	else if (map[y][x] == '1')
		img = mlx_xpm_file_to_image(mlx, "img/ile1.xpm", &width, &height);
	else if (map[y][x] == 'P' && (map[y + 1][x] == 'E' || map[y + 1][x] == 'E'
			|| map[y][x - 1] == 'E' || map[y][x + 1] == 'E'))
		img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
	else if (map[y][x] == 'P')
		img = mlx_xpm_file_to_image(mlx, "img/personnage.xpm", &width, &height);
	else if (map[y][x] == 'E')
		img = mlx_xpm_file_to_image(mlx, "img/reelexit.xpm", &width, &height);
	else if (map[y][x] == 'C' && y % 2 == 0)
		img = mlx_xpm_file_to_image(mlx, "img/c1.xpm", &width, &height);
	else if (map[y][x] == 'C')
		img = mlx_xpm_file_to_image(mlx, "img/c2.xpm", &width, &height);
	else if (map[y][x] >= 51 && map[y][x] <= 53)
		img = sous_img(y, x, mlx, map);
	return (img);
}

void	put_img(void *mlx, void *win, char **map)
{
	void	*img;
	int		y;
	int		x;

	y = gety(map) + 1;
	x = getx(map) + 1;
	while (--y >= 0)
	{
		x = getx(map) + 1;
		while (--x >= 0)
		{
			if (map && map[y] && map[y][x])
			{
				img = ft_choose_img(x, y, map, mlx);
				if (img)
				{
					mlx_put_image_to_window(mlx, win, img, x * 70, y * 70);
					mlx_destroy_image(mlx, img);
				}
				else
					mlx_des(win, mlx);
			}
		}
	}
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*param[2];

	if (ac != 2)
		return (ft_printf("tu as mis %d arguments\n", ac - 1), 0);
	map = gest_map(av[1]);
	if (!map)
		return (ft_printf("error\n"), 0);
	add_enemie(&map);
	moov_enemie(&map, NULL, NULL);
	swap_map(&map, 0, NULL, NULL);
	mlx = mlx_init();
	if (!mlx)
		return (ft_free_map(NULL), ft_printf("error\n"), -1);
	win = mlx_new_window(mlx, getx(map) * 70, gety(map) * 70, "so_long");
	if (!win)
		return (ft_free_map(NULL), free(mlx), ft_printf("error\n"), -1);
	param[0] = (void *)win;
	param[1] = (void *)mlx;
	put_img(mlx, win, map);
	mlx_hook(win, 17, 0, close_window, param);
	mlx_loop_hook(mlx, moov_enemie2, param);
	return (mlx_key_hook(win, m, param), mlx_loop(mlx), ft_printf("error\n"), 0);
}
