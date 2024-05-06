/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:42:24 by bdany             #+#    #+#             */
/*   Updated: 2024/05/06 11:27:38 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		g_perm;

void	sign_recept(int sign)
{
	(void)sign;
	g_perm = 1;
}

void	char_to_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_perm = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_perm != 1)
			;
	}
}

void	send_char(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bit(pid, str[i]);
		i++;
	}
	char_to_bit(pid, 0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (write(2, "Usage : ./client (PID) (string to send).\n", 7));
	pid = ft_atoi(argv[1]);
	if (pid == 0 || (ft_isdigit(argv[1]) == 1))
		return (write(2, "Is an invalid PID.\n", 19));
	if (kill(pid, 0))
		return (write(2, "Error : can't send signal to PID.\n", 34));
	signal(SIGUSR1, sign_recept);
	send_char(argv[2], pid);
	return (0);
}
