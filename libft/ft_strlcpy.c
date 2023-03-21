/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:05:18 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/23 16:22:23 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * strlcpy() and strlcat() copy and concatenate strings with the same input para
 * meters and output result as snprintf(3)
 *
 * strlcpy() and  strlcat() take the full size of the destination buffer and 
 * guarantee NUL termination, with the help of dstsize.
 * - If the return value is >= dstsize, the output string has been truncated. 
 * - It is the caller's responsibility to handle this.
 *
 * strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL
 * terminating the result if dstsize is not 0.
 *
 * If the src and dst strings overlap, the behavior is undefined.
 * Improper use of the strncpy() and strncat() functions can result in buffer o
 * verflow vulnerabilities.
 * */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1 && src[i] != '\0')
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (len);
}
