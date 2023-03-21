/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:44 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/23 16:07:45 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * memset() function writes 'len' bytes of value 'c' (converted to an unsigned
 * char) to a string 'b'.
 *
 * */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pointer_to_b;

	pointer_to_b = (char *)b;
	while (len--)
		pointer_to_b[len] = (unsigned char)c;
	return (b);
}
