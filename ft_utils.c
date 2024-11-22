/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:26:57 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/22 11:26:57 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	read;

	read = 0;
	while (*str)
		read += write(1, str++, 1);
	return (read);
}

long int	ft_putnbr_base(long int nb, long int len_base)
{
	static long int	read;
	char			res;
	char			*base;

	read = 0;
	if (len_base == 10)
		base = "0123456789";
	else
		base = "0123456789abcdef";
	if (nb < 0)
	{
		read += write(1, "-", 1);
		nb *= -1;
	}
	if (nb / len_base != 0)
		ft_putnbr_base(nb / len_base, len_base);
	return (read += write(1, &base[nb % len_base], 1));
}
