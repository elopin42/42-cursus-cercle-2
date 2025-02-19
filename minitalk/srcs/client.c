/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:21:16 by elopin            #+#    #+#             */
/*   Updated: 2025/02/18 15:11:33 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int		ft_atoi(const char *ts);

void	send_signal(char car, pid_t pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((car >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
		return (ft_printf("mauvais format\n"), 0);
	i = -1;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (0);
	while (av[2][++i])
		send_signal(av[2][i], pid);
	return (0);
}

int	ft_atoi(const char *ts)
{
	int	k;
	int	i;
	int	s;

	i = 0;
	k = 0;
	s = 1;
	while ((ts[i] >= 9 && ts[i] <= 13) || ts[i] == 32)
		i++;
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
	if (k * s >= 2147483647)
		return (2147483647);
	if (k * s <= -2147483648)
		return (-2147483648);
	return (k * s);
}
