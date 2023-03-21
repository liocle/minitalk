/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:11:27 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:21:51 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	ft_putendl_fd() writes the string 's' on the file descriptor 'fd' and add 
 *	a line break in the end.
 */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
