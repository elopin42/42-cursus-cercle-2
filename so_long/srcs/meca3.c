/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meca3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:51:02 by elopin            #+#    #+#             */
/*   Updated: 2025/01/22 21:13:10 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count_nbr(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i += 1;
	}
	return (i + 1);
}

char	*my_ft_itoa(int n)
{
	char	*str;
	int		c;

	c = ft_count_nbr(n);
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	str[c--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[c] = n % 10 + '0';
		n /= 10;
		c--;
	}
	return (str);
}

int	ft_strstr(const char *b, const char *li)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*li)
		return (0);
	while (b[i])
	{
		j = 0;
		while (li[j] == b[i] && b[i])
		{
			i++;
			j++;
		}
		if (!li[j])
			return (1);
		i -= j;
		i++;
	}
	return (0);
}

void	ft_free_map(char ***tmap)
{
	int			i;
	static char	**map = NULL;

	i = 0;
	if (tmap)
		map = *tmap;
	else if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	mlx_des(void *win, void *mlx)
{
	mlx_clear_window(mlx, win);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	ft_free_map(NULL);
	free(mlx);
	ft_printf("fin de partie (;\n");
	exit(0);
}
