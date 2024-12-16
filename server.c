/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:07:03 by jenibaud          #+#    #+#             */
/*   Updated: 2024/12/16 14:14:16 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static char	*ft_strjoin_char(char *s1, char const s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	s2_len = 1;
	str = ft_calloc(((s1_len + s2_len) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	str[s1_len] = s2;
	free(s1);
	return (str);
}

static void	ft_handler(int sig, siginfo_t *signals, void *context)
{
	static int	bit;
	static int	i;
	static char	*str = NULL;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i != '\0')
			str = ft_strjoin_char(str, i);
		else
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		bit = 0;
		i = 0;
	}
	usleep(1);
	kill(signals->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause ();
	}
	return (0);
}
