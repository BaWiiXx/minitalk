/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:50:45 by bdany             #+#    #+#             */
/*   Updated: 2024/04/22 17:48:21 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printbit(int signal)
{
	int	bit;
	int	i;

	if (signal == SIGUSR1)
		;
	i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	(void)argv;

	if (argv != 1)
		return (write(2, "Error\n", 6));
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, printbit);
		signal(SIGUSR2, printbit);
		wait();
	}
	return (0);
}