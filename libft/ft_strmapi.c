/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:44:21 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 13:40:49 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Applies the function 'f' to each character of the string 's' and passing 
 * its index as first argument to create a new string (with malloc (3)) 
 * resulting from successive applications of 'f'.
 *
 * Return value:
 * The string created from the successive applications of 'f'.
 * Returns NULL if the allocation fails.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_length;
	size_t	i;
	char	*ptr_to_s;

	i = 0;
	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	ptr_to_s = (char *)malloc((sizeof(char) * s_length) + 1);
	if (ptr_to_s == NULL)
		return (NULL);
	while (s[i])
	{
		ptr_to_s[i] = f((unsigned int) i, s[i]);
		i++;
	}
	ptr_to_s[s_length] = '\0';
	return (ptr_to_s);
}
