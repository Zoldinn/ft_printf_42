/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:30:40 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/22 10:30:40 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <limits.h>
#define age (INT_MIN + 2)
int	ft_print_format(unsigned char format, va_list ap)
{
	int	read;

	read = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(ap, long int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(ap, long int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(ap, long int), "0123456789ABCDEF"));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		read;

	read = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			read += ft_print_format(*(++format), ap);
			if (!read)
				return (0);
		}
		else
			read += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (read);
}

int	main(void)
{
	int	read;
	int	read2;

	read = ft_printf("Holla %s %c You're %d, so %i years you live and you're age in hexa is %X or %x\n", "paco", '!', age, age, age, age);
	read2 = printf("Holla %s %c You're %d, so %i years you live and you're age in hexa is %X or %x\n", "paco", '!', age, age, age, age);
	
	printf("\n--- read ---\n");
	printf("ft_printf : %d\n", read);
	printf("printf : %d\n", read2);
	return (0);
}
