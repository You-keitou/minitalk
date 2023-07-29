/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:01:09 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/29 18:27:02 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signal(int sig)
{
	static int	index = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << index);
	index++;
	if (index == CHAR_BIT)
	{
		ft_printf("%c", c);
		index = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
	return (0);
}
