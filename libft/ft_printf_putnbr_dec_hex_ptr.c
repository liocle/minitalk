/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec_hex_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:01 by lclerc            #+#    #+#             */
/*   Updated: 2022/12/09 17:03:45 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pointer(size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_putnbr_pointer(n / 16);
		i += ft_putnbr_pointer(n % 16);
	}
	if (n >= 0 && n <= 15)
	{
		if (n == 0)
		i += ft_putchar(n + '0');
		else if (n <= 9)
		{
			i += ft_putchar(n + '0');
		}
		else
			i += ft_putchar(n - 10 + 'a');
	}
	return (i);
}

int	ft_putnbr_hexa_lower(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_putnbr_hexa_lower(n / 16);
		i += ft_putnbr_hexa_lower(n % 16);
	}
	if (n >= 0 && n <= 15)
	{
		if (n <= 9)
		{
			i += ft_putchar(n + '0');
		}
		else
			i += ft_putchar(n - 10 + 'a');
	}
	return (i);
}

int	ft_putnbr_hexa_upper(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_putnbr_hexa_upper(n / 16);
		i += ft_putnbr_hexa_upper(n % 16);
	}
	if (n >= 0 && n <= 15)
	{
		if (n <= 9)
		{
			i += ft_putchar(n + '0');
		}
		else
			i += ft_putchar(n - 10 + 'A');
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putnbr_unsigned(n % 10);
	}
	if (n >= 0 && n <= 9)
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			i += ft_putchar('-');
			i += ft_putchar('2');
			n = 147483648;
		}
		else
		{
			i += ft_putchar('-');
			i += ft_putnbr(n * -1);
		}
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		i += ft_putchar(n + '0');
	return (i);
}
