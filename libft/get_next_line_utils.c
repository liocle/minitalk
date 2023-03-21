/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:32:16 by lclerc            #+#    #+#             */
/*   Updated: 2023/03/17 09:23:03 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(const char *s, int c)
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

size_t	gnl_ft_strlen(const char *s)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0')
		p++;
	return (p - s);
}

char	*gnl_ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*joined_string;
	size_t	joined_string_length;

	if (!s1 || !s2)
		return (NULL);
	s2_len = 0;
	if (*s2 != '\0')
		s2_len = gnl_ft_strlen(s2);
	if (!gnl_ft_strlen(s1) && !s2_len)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	joined_string_length = gnl_ft_strlen(s1) + s2_len + 1;
	joined_string = (char *)malloc(joined_string_length * sizeof(char) + 1);
	if (joined_string == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	gnl_ft_strlcpy(joined_string, s1, joined_string_length);
	gnl_ft_strlcat(joined_string, s2, joined_string_length);
	return (joined_string);
}

size_t	gnl_ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;

	i = 0;
	src_length = BUFFER_SIZE;
	dst_length = 0;
	if (dst)
		dst_length = gnl_ft_strlen(dst);
	if (dst_length >= dstsize)
	{
		return (dstsize + src_length);
	}
	while (dst_length + i < dstsize && src[i] != '\0')
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = gnl_ft_strlen(src);
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
