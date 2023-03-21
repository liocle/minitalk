/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:42:08 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 13:45:33 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Applies the function 'f' on each character of the string passed as argument,
 * passing its index as first argument. Each character is passed by address to
 * 'f' to be modified if necessary. 
 *
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f((unsigned int) i, &s[i]);
		i++;
	}	
}
