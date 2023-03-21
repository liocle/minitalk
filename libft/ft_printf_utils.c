/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:00:52 by lclerc            #+#    #+#             */
/*   Updated: 2022/12/09 16:55:33 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static	size_t	ft_strlen(const char *s)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0')
		p++;
	return (p - s);
}

int	ft_putstr(char *s)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (s == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	length = ft_strlen(s);
	while (i < length)
	{
		i += ft_putchar(*s++);
	}
	return (i);
}

int	ft_print_pointer(size_t n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr_pointer(n);
	return (i);
}
