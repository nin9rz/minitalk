/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:44:53 by jenibaud          #+#    #+#             */
/*   Updated: 2024/12/16 14:22:12 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	g_signal;

static void	ft_wait_for_server(int sig)
{
	(void)sig;
	g_signal = 1;
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;
	int	timer;

	bit = 0;
	g_signal = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		signal(SIGUSR1, ft_wait_for_server);
		timer = 0;
		while (g_signal == 0)
		{
			usleep(1);
			if (timer > 5000)
				exit(1);
			timer++;
		}
		g_signal = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= -1)
		{
			return (0);
		}
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\0');
	}
	else
	{
		ft_printf("Error: wrong format.Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
