/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meca4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:29:45 by elopin            #+#    #+#             */
/*   Updated: 2025/01/23 16:04:41 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sous_choose_img(int y, int x, void *mlx)
{
	void		*img;
	int			width;
	int			height;
	static int	s = 0;

	img = NULL;
	if ((x + y) % 5 == 0)
		img = mlx_xpm_file_to_image(mlx, "img/eau1.xpm", &width, &height);
	else if (x + y % 4 == 0)
		img = mlx_xpm_file_to_image(mlx, "img/eau2.xpm", &width, &height);
	else if ((y + x) % 3 == 0)
		img = mlx_xpm_file_to_image(mlx, "img/eau3.xpm", &width, &height);
	else if ((y + x) % 2 == 0)
		img = mlx_xpm_file_to_image(mlx, "img/eau4.xpm", &width, &height);
	else
		img = mlx_xpm_file_to_image(mlx, "img/eau5.xpm", &width, &height);
	return (s++, img);
}

void	help_me(int e, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (e >= 1)
	{
		pjoueur(map, &x, &y, 51);
		swap_case(&map[y][x], &map[y + ((rand() % 3) - 1)][x + ((rand() % 3)
				- 1)], 0);
	}
	if (e >= 2)
	{
		pjoueur(map, &x, &y, 52);
		swap_case(&map[y][x], &map[y + ((rand() % 3) - 1)][x + ((rand() % 3)
				- 1)], 0);
	}
	if (e == 3)
	{
		pjoueur(map, &x, &y, 53);
		swap_case(&map[y][x], &map[y + ((rand() % 3) - 1)][x + ((rand() % 3)
				- 1)], 0);
	}
}

char	*help_mev2(int fd)
{
	char	*str;
	char	*tmp;

	str = get_next_line(fd);
	tmp = get_next_line(fd);
	if (!str)
		return (NULL);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (str);
}

int	help_mev3(char **map, int i)
{
	int	x;
	int	y;
	int	b;

	x = 0;
	y = 0;
	b = 0;
	pjoueur(map, &x, &y, 'P');
	if (i == 1)
		b = swap_case(&map[y][x], &map[y - 1][x], 1);
	else if (i == 2)
		b = swap_case(&map[y][x], &map[y][x + 1], 1);
	else if (i == 3)
		b = swap_case(&map[y][x], &map[y + 1][x], 1);
	else if (i == 4)
		b = swap_case(&map[y][x], &map[y][x - 1], 1);
	return (b);
}

void	*sous_img(int y, int x, void *mlx, char **map)
{
	void	*img;
	int		width;
	int		height;

	img = NULL;
	if (map[y][x] == 51)
		img = mlx_xpm_file_to_image(mlx, "img/ennemie.xpm", &width, &height);
	else if (map[y][x] == 52)
		img = mlx_xpm_file_to_image(mlx, "img/mechant.xpm", &width, &height);
	else if (map[y][x] == 53)
		img = mlx_xpm_file_to_image(mlx, "img/mechant2.xpm", &width, &height);
	return (img);
}
