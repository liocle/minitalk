/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:15:51 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/22 13:03:45 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The calloc() contiguously allocates enough space for count objects that
 * are size bytes of memory each and returns  a pointer to the allocated memory.
 * The allocated memory is  filled with bytes of value zero.
 *
 * This function returns a pointer to the allocated memory, or NULL if the 
 * request fails.
 *
 * From IBM doc:
 * The return value is NULL if there is not enough storage, or if num or size
 * is 0.
 * From Linux Man Page https://linux.die.net/man/3/calloc :
 * The calloc() function allocates memory for an array of nmemb elements of 
 * size bytes each and returns a pointer to the allocated memory. The memory 
 * is set to zero. If nmemb or size is 0, then calloc() returns either NULL,
 * or a unique pointer value that can later be successfully passed to free().
 */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer_to_allocated_memory;

	if (count != 0 && size != 0 && count * size / size != count)
		return (NULL);
	pointer_to_allocated_memory = (void *)malloc(size * count);
	if (pointer_to_allocated_memory == NULL)
		return (NULL);
	ft_bzero(pointer_to_allocated_memory, count * size);
	return (pointer_to_allocated_memory);
}	
