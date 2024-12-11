/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:07:03 by jenibaud          #+#    #+#             */
/*   Updated: 2024/12/11 17:57:01 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	__pid_t	pid;
	pid = getpid();
	
	ft_printf("Server PID : %d\n", pid);
	while (1)
	{
		
	}
}
