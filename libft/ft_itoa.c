/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:02 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/24 11:25:38 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * itoa() converts an integer to a string.
 * 
 * Returns:
 * - string of characters 
 * - NULL if allocation fails
 *
 * malloc can be used. 
 */

#include "libft.h"

int	get_length(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length++;
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}	

char	*ft_itoa(int n)
{
	char	*ascii_string;
	int		length;
	long	number;

	number = n;
	length = get_length(number);
	ascii_string = (char *)malloc(length * sizeof(char) + 1);
	if (!ascii_string)
		return (NULL);
	ascii_string[length--] = '\0';
	if (number < 0)
	{
		ascii_string[0] = '-';
		number = -number;
	}
	while (number >= 10)
	{
		ascii_string[length--] = number % 10 + '0';
		number = number / 10;
	}
	ascii_string[length] = number + '0';
	return (ascii_string);
}
