/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:42:36 by elopin            #+#    #+#             */
/*   Updated: 2024/11/29 23:14:41 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_string(char *s)
{
	int		i;
	char	*null;
	int		count;

	i = 0;
	count = 0;
	null = "(null)";
	if (!s)
	{
		while (null[i])
			ft_print_char(null[i++]);
		return (6);
	}
	else
		while (s[i])
			count += ft_print_char(s[i++]);
	return (count);
}
