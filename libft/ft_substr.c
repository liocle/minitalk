/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:24:56 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:00:23 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_substr() allocates with malloc() and returns a string of characters from
 * string 's'. The new string starts at index 'start' and has as maximum size
 * 'len'
 *
 * ft_substr() returns a pointer to the new string, or NULL if the memory 
 * allocation has failed.
 *
 */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	str_len;
	size_t	i;		

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while ((i < len) && s)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
