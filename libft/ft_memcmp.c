/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:38:29 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/22 17:43:33 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	memcmp() compares binary byte buffers of N bytes between s1 and s2.
 *	Unlike strcmp, comparison does not stop when meeting NULL terminator '\0'.
 *	
 *	memcmp() returns zero if s1 identical to s2, otherwise returns the dif-
 *	ference	between the first two differing bytes (treated as unsigned char
 *	values, so that '\200' > '\0'. 
 *
 * 	Return values:
 *  < 0	if s1 < s2
 *	0 length string are always identical.
 *	> 0 if s1 > s2 
 *  Last argument is number of bytes to compare.
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return (0);
}
