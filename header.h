/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:52 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/25 16:06:22 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putnbr(long long int nb, int *read);
int	ft_putnbr_base(unsigned long int nb, char *base, int *read);
int	ft_putaddress(void *ptr, int *read);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif
