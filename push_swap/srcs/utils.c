/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:06:44 by elopin            #+#    #+#             */
/*   Updated: 2025/02/17 17:28:18 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		new_str = (char *)malloc(1);
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < (size_t)ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *ts, t_pile *p)
{
	long	k;
	int		i;
	int		s;

	i = 0;
	k = 0;
	s = 1;
	if (ts[i] == '-' || ts[i] == '+')
	{
		if (ts[i] == '-')
			s *= -1;
		i++;
	}
	while (ts[i] >= '0' && ts[i] <= '9')
	{
		k = (k * 10) + ts[i] - '0';
		i++;
	}
	if (k * s > 2147483647 || k * s < -2147483648)
		p->error = -1;
	if (k * s >= 2147483647)
		return (2147483647);
	if (k * s <= -2147483648)
		return (-2147483648);
	return ((int)k * s);
}

int	ft_my_strchr(char *s, char c)
{
	int	i;
	int	len;

	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			if (s[i] == c)
				return (i);
			i++;
		}
		return (i);
	}
}

int	check_valid(char **av)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (av[++y])
	{
		i = 0;
		if (av[y][i] == '-' || av[y][i] == '+')
			i++;
		if (av[y][i] == '\0')
			return (0);
		while (av[y][i])
		{
			if (av[y][i] < '0' || av[y][i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}
