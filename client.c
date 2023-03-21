/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:12:56 by lclerc            #+#    #+#             */
/*   Updated: 2023/03/21 14:51:54 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// (1 << i) generates value where only i'th bit is set
// value & (1 << i) is non-zero only if i'th bit is set in value

// SIGUSR1 is associated to unset bit = 0. 
// SIGUSR2 is associated to set bit = 1.

#include "minitalk_common.h"

static void	send_bits(pid_t pid, char *string)
{
	int		i;
	size_t	j;
	size_t	delay;
	size_t	length;
	char	c;

	j = 0;
	length = ft_strlen(string);
	delay = (120 + (length / 100) + (length / 200) + (length / 1000));
	while (j < length)
	{
		i = 0;
		c = string[j++];
		while (i < 8)
		{
			if (c & (1 << i++))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(delay);
		}
	}
}

static void	print_error(int argc, pid_t server_pid, char **argv)
{
	if (argc != 3)
	{
		ft_printf(R"client:\tinvalid number of arguments\n");
		ft_printf("usage:\tclient [Server PID] [String]\n"RES);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0))
	{
		ft_printf(R"client:\tinvalid server PID\n");
		ft_printf("usage:\tclient [Server PID] [String]\n"RES);
		exit(1);
	}
	if (argv[2][0] == '\0')
	{
		ft_printf(R"client:\tempty string\n");
		ft_printf("usage:\tclient [Server PID] [String]\n"RES);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		print_error(argc, 0, argv);
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) || argv[2][0] == '\0')
		print_error(argc, server_pid, argv);
	ft_printf("String length\t[%i]\n", ft_strlen(argv[2]));
	ft_printf("ServerPID\t[%i]\nString\t\t[%s]\n", server_pid, argv[2]);
	send_bits(server_pid, argv[2]);
	return (0);
}
