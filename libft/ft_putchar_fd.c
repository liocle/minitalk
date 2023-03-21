/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:34 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:18:31 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_putchar_fd() write the character 'c' on the give filedescriptor 'fd'
 */

void	ft_putchar_fd(char c, int fd)
{	
	write (fd, &c, 1);
}
