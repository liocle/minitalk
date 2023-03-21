/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:46:48 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:19:37 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Outputs the string 's' to the given file descriptor.
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
			ft_putchar_fd(*s++, fd);
	}
}
