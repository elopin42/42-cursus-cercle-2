/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:50:37 by elopin            #+#    #+#             */
/*   Updated: 2024/12/01 20:41:54 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// cc -Wall -Werror -Wextra *.c

static int	ft_sub_printf(char c, va_list(args), int t)
{
	if (c == 'c')
		t = ft_print_char(((char)va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		t = ft_print_int(va_arg(args, int));
	else if (c == '%')
		t = ft_print_char('%');
	else if (c == 's')
		t = ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		t += ft_ad(va_arg(args, void *), "0123456789abcdef", 16, 1);
	else if (c == 'x')
		t = ft_ad(va_arg(args, void *), "0123456789abcdef", 16, 0);
	else if (c == 'X')
		t = ft_ad(va_arg(args, void *), "0123456789ABCDEF", 16, 0);
	else if (c == 'u')
		t = ft_ad(va_arg(args, void *), "0123456789", 10, 0);
	return (t);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
			count += ft_sub_printf(s[++i], args, 0);
		else
		{
			ft_print_char(s[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	k;
	int	h;

	k = 0;
	h = 0;
	k = printf(" %u ", "48B");
	h = ft_printf(" %u ", "48B");
	printf("%i, %i", k, h);
	return (0);
}*/
