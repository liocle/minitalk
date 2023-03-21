/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:18:03 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 12:51:36 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Allocates with malloc() and returns a copy of 's1' with the characters
 *	specified in 'set' removed from the beginning and the end of the string.
 * 	
 * 	Returns the trimmed string or NULL if the allocaiton fails.
 */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	size_t	i;
	int		end;
	int		start;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (start != end - 1 && set[i])
	{
		if (set[i] != s1[start])
			i++;
		else
		{
			i = 0;
			start += 1;
		}
	}
	return (start);
}

static int	find_end(char const *s1, char const *set, int mark_start)
{
	size_t	i;
	int		end;

	i = 0;
	end = ft_strlen(s1);
	while (mark_start != end && set[i])
	{
		if (set[i] != s1[end - 1])
			i++;
		else
		{
			i = 0;
			end -= 1;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		mark_start;
	int		mark_end;

	if (!s1 || !set)
		return (NULL);
	mark_start = find_start(s1, set);
	mark_end = find_end(s1, set, mark_start);
	trimmed_str = (char *)malloc((mark_end - mark_start + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	if (mark_start == mark_end - 1)
		*trimmed_str = '\0';
	ft_strlcpy(trimmed_str, s1 + mark_start, (mark_end - mark_start) + 1);
	return (trimmed_str);
}
