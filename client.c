/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:01:07 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/29 18:49:29 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, char c)
{
	int	index;

	index = 0;
	while (index < CHAR_BIT)
	{
		if (c & (1 << index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	index;

	index = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99998)
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
		while (argv[2][index])
		{
			send_char(pid, argv[2][index]);
			index++;
		}
		send_char(pid, '\0');
	}
	else
		ft_printf("Usage: ./client [server PID] [message]\n");
}
