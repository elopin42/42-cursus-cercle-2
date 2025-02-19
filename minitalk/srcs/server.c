/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:04:16 by elopin            #+#    #+#             */
/*   Updated: 2025/02/18 02:52:43 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int sig)
{
	static char	let;
	static int	bytes = 0;

	let |= (sig == SIGUSR1);
	bytes++;
	if (bytes == 8)
	{
		ft_printf("%c", let);
		bytes = 0;
		let = 0;
	}
	else
		let <<= 1;
}

int	main(void)
{
	ft_printf("\npid --> %d\n\n", getpid());
	ft_printf("--- Waiting for message ---\n\n");
	while (42)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
