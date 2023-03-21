/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:49:44 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/23 16:17:45 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * The memmove() function copies len bytes from string src to string dst. the 2 
 * strings may overlap. If the beginning of destination overlaps with end of the
 * source, copying  should be done backward.
 *
 * The difference here with memcpy() is that if the source pointer is located 
 * before the destination pointer, it is needed to start copying from 'len'
 * to avoid overlapping.
 *
 */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*destination;

	i = 0;
	source = (char *)src;
	destination = (char *)dst;
	if (!source && !destination)
		return (NULL);
	if (source < destination)
	{
		source = source + len - 1;
		destination = destination + len - 1;
		while (len--)
			*destination-- = *source--;
	}
	else
		ft_memcpy(destination, source, len);
	return (dst);
}
