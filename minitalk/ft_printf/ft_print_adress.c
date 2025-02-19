/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:22:24 by elopin            #+#    #+#             */
/*   Updated: 2024/12/01 20:40:32 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

static int	ft_ads(unsigned long adr, char *base, unsigned long nbr)
{
	int	count;

	count = 0;
	if (adr >= nbr)
		count += ft_ads(adr / nbr, base, nbr);
	count += ft_print_char(base[adr % nbr]);
	return (count);
}

static int	ft_adss(unsigned int adr, char *base, long nbr)
{
	int	count;

	count = 0;
	if (adr >= nbr)
		count += ft_ads(adr / nbr, base, nbr);
	count += ft_print_char(base[adr % nbr]);
	return (count);
}

int	ft_ad(void *adr, char *base, unsigned long nbr, int j)
{
	int				count;
	unsigned long	adress;
	unsigned int	addres_long;

	count = 0;
	adress = 0;
	addres_long = 0;
	if (j)
		adress = (unsigned long)adr;
	else
		addres_long = (unsigned long)adr;
	if (adress && j)
		count += ft_print_string("0x");
	if (!adress && j)
		count += ft_print_string("(nil)");
	else if (j)
		count += ft_ads(adress, base, nbr);
	else
		count += ft_adss(addres_long, base, nbr);
	return (count);
}
