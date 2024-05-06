/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:50:45 by bdany             #+#    #+#             */
/*   Updated: 2024/05/06 11:38:43 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_bit(int sign, siginfo_t *info, void *context)
{
	static unsigned char	bit;
	static unsigned char	i;
	static char				*temp = NULL;

	(void)context;
	if (sign == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (temp == NULL)
			temp = calloc(1, sizeof(char));
		temp = ft_strjoin_char_free(temp, i);
		if (i == 0)
		{
			ft_putstr_fd(temp, 1);
			free(temp);
			temp = NULL;
		}
		i = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sign;

	(void)argv;
	sign.sa_sigaction = print_bit;
	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	if (argc != 1)
		return (write(2, "Usage : ./server\n", 6));
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (1)
		pause();
	return (0);
}
