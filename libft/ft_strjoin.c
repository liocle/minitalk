/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:20:30 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:04:39 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 *	ft_strjoin() is returning a new string out of the concatenation of s1 and s2.
 *	
 *	s1 is the prefixed string, and s2 the suffix.
 *
 *	The returned value is NULL if allocation fails.
 *
 *	Malloc can be used.
 * */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	joined_string_length;

	if (!s1 || !s2)
		return (NULL);
	joined_string_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_string = (char *)malloc(joined_string_length * sizeof(char) + 1);
	if (joined_string == NULL)
		return (NULL);
	ft_strlcpy(joined_string, s1, joined_string_length);
	ft_strlcat(joined_string, s2, joined_string_length);
	return (joined_string);
}
