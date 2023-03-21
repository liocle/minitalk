/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:26:29 by lclerc            #+#    #+#             */
/*   Updated: 2022/12/09 17:24:43 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	format_me(va_list arg_pointer, const char *format)
{
	int			i;

	if (*format == 'c')
		i = ft_putchar(va_arg(arg_pointer, int));
	if (*format == 's')
		i = ft_putstr(va_arg(arg_pointer, char *));
	if (*format == 'd' || *format == 'i')
		i = ft_putnbr(va_arg(arg_pointer, int));
	if (*format == 'x')
		i = ft_putnbr_hexa_lower(va_arg(arg_pointer, unsigned int));
	if (*format == 'X')
		i = ft_putnbr_hexa_upper(va_arg(arg_pointer, unsigned int));
	if (*format == '%')
		i = ft_putchar('%');
	if (*format == 'u')
		i = ft_putnbr_unsigned(va_arg(arg_pointer, int));
	if (*format == 'p')
		i = ft_print_pointer((size_t)va_arg(arg_pointer, void *));
	return (i);
}

static	int	ft_vprintf(va_list arg_pointer, const char	*format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			i += format_me(arg_pointer, &format[++j]);
			j++;
		}
		else if (format[j] != '\0')
		{
			i += ft_putchar(format[j++]);
		}
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_pointer;
	int		done;

	done = 0;
	va_start (arg_pointer, format);
	done = ft_vprintf(arg_pointer, format);
	va_end (arg_pointer);
	return (done);
}
