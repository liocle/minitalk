/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:47 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/22 14:42:12 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * DESCRIPTION:
 *
 * The strchr() function locates the first occurrence of c (converted to a char)
 * in the string pointed to by s.  The terminating null character is considered 
 * to be part of the string; therefore if c is `\0', the functions locate the 
 * terminating `\0' *
 *
 * RETURN VALUES:
 * The functions strchr() and strrchr() return a pointer to the located 
 * character, or NULL if the character does not appear in the string.
 *
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((*p == '\0') && (*p == c))
		return (p);
	return (0);
}
