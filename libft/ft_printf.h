/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:05:40 by lclerc            #+#    #+#             */
/*   Updated: 2022/12/09 17:28:25 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_pointer(size_t n);
int	ft_putnbr_hexa_lower(unsigned int n);
int	ft_putnbr_hexa_upper(unsigned int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_print_pointer(size_t n);

#endif
