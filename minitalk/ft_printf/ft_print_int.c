/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:15:16 by elopin            #+#    #+#             */
/*   Updated: 2024/11/30 19:55:31 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_int(int c)
{
	int		count;

	count = 0;
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (c < 0)
	{
		c *= -1;
		write(1, "-", 1);
		count++;
	}
	if (c > 9)
	{
		count += ft_print_int(c / 10);
		ft_print_int(c % 10);
	}
	else
		ft_print_char(c + '0');
	return (count + 1);
}
