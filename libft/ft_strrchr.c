/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:35:11 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/23 15:58:26 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * strrchr() is similar to strchr() except that it locates the last occurence of
 * 'c'.
 *
 * The function returns a pointer to the located character, or NULL if character
 * is not found in the string.
 *
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	length;

	length = ft_strlen(s);
	p = (char *)s;
	while (length + 1 > 0)
	{
		if (p[length] == (char)c)
			return (p + length);
		length--;
	}
	return (NULL);
}
