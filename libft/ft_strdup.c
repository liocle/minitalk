/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:31:02 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 10:18:05 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strdup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it. The same pointer can be used
 * to free(3).
 *
 * If insufficient memory is available, NULL is returned and errno is set to 
 * ENOMEM (not enough space/cannot allocate memory). 
 */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	int		length_s1;

	length_s1 = ft_strlen(s1);
	duplicate = (char *)malloc(length_s1 * sizeof(char) + 1);
	if (duplicate == NULL)
		return (NULL);
	duplicate[length_s1] = '\0';
	while (length_s1)
	{
		length_s1--;
		duplicate[length_s1] = s1[length_s1];
	}
	return (duplicate);
}
