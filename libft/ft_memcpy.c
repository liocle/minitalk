/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:47:54 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/23 16:11:57 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	memcpy() copies n bytes from memory area src to memory area dst. If dst and 
 *	src overlap, behaviour is undefined, even though some compilers may handle 
 *	it. This is the main difference with memmove(), which can handle overlapping
 *	memory addresses using a buffer. See memmove()
 *
 *	memcpy() function returns the original value of dst.
 *
 */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (!source && !destination)
		return (NULL);
	while (n)
	{
		*destination = *source;
		destination++;
		source++;
		n--;
	}
	return (dst);
}
