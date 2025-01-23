/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:21:26 by elopin            #+#    #+#             */
/*   Updated: 2025/01/23 17:11:42 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin_check(char const *s1, char const *s2);

char	**gest_map(char *ber)
{
	int		fd;
	char	**map;
	char	*str;

	if (!(ft_strstr(ber, ".ber")))
		return (ft_printf("ton fichier n'est pas un .ber\n"), NULL);
	if (!(ft_strstr(ber, "/")))
		ber = ft_strjoin_check("maps/", ber);
	else
		ber = ft_substr(ber, 0, ft_strlen(ber));
	fd = open(ber, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (free(ber), NULL);
	str = help_mev2(fd);
	if (!str)
		return (free(ber), NULL);
	map = ft_split(str, '\n');
	if (!map)
		return (free(str), free(ber), ft_printf("erreur en sorti de split \n"),
			NULL);
	ft_free_map(&map);
	if (!(valid_map(map)))
		return (free(str), free(ber), ft_free_map(NULL), NULL);
	return (free(str), free(ber), map);
}

char	*ft_strjoin_check(char const *s1, char const *s2)
{
	char			*str;
	unsigned long	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen((char *)s1), ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen((char *)s1)])
	{
		str[i] = s2[i - ft_strlen((char *)s1)];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t ec, size_t es)
{
	void	*ptr;
	size_t	i;
	size_t	t;

	i = 0;
	t = ec * es;
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	while (i < t)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

int	pjoueur(char **map, int *a, int *b, char p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == p)
			{
				if (a)
					return ((*b) = y, (*a) = x, 1);
				else
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// i1 = haut i2 = droite i3 = bas i4 = gauche i0 = rien faire;

int	swap_map(char ***tmap, int i, void *win, void *mlx)
{
	static char	**map = NULL;
	int			y;
	int			x;
	static int	a = 0;
	int			b;

	b = 0;
	y = 0;
	x = 0;
	if (tmap != NULL)
		return (map = (*tmap), 0);
	b = help_mev3(map, i);
	if (!(pjoueur(map, &x, &y, 'P')))
		return (-2);
	if ((b == -1) && (c_count(map, 'C') == 0))
		return (ft_free_map(NULL), ft_printf("tu as reussi (;\n"), b);
	else if ((b == -1) && (c_count(map, 'C') > 0))
		return (ft_printf("ne rejoins pas ton ami sans alcool\n"), a);
	else if ((b != -1) && (b != 0))
		ft_printf("bravo tu as fait %d pas\n", ++a);
	return (put_img(mlx, win, map), a);
}
