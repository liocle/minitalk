/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:23:42 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 10:32:29 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strlcpy() and strlcat() functions copy and concatenate strings with the 
 * same input parameters and output result as snprintf(3).  They are designed 
 * to be safer, more consistent, and less error prone replacements for the 
 * easily misused functions strncpy(3) and strncat(3).
 *
 * strlcpy() and strlcat() take the full size of the destination buffer and 
 * guarantee NUL-termination if there is room.  Note that room for the NUL 
 * should be included in dstsize.
 *
 * strlcat() appends string src to the end of dst.  It will append at most 
 * dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
 * dstsize is 0 or the original dst string was longer than dstsize (in practice
 * this should not happen as it means that either dstsize is incorrect or that 
 * dst is not a proper string).
 * 	
 * If the src and  dst strings overlap, the behavior is undefined.
 *
 * strlcat returns the total length of the string 
 * */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;

	i = 0;
	src_length = ft_strlen(src);
	dst_length = 0;
	if (dst)
		dst_length = ft_strlen(dst);
	if (dst_length >= dstsize)
		return (dstsize + src_length);
	while (dst_length + i < dstsize - 1 && src[i] != '\0')
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}
