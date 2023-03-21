/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:13:06 by lclerc            #+#    #+#             */
/*   Updated: 2023/03/21 14:51:53 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGUSR1 is associated to unset bit = 0. 
// SIGUSR2 is associated to set bit = 1.
// Bit setting occurs when SIGUSR2 is caught, SIGUSR1 moves the bitshifting
// index only.
// Bit clearing takes place as the index 'i' is reinitialized.

#include "minitalk_common.h"

static void	sig_handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR2)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server's PID is: <%i>\n", pid);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
