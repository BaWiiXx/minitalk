/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:42:24 by bdany             #+#    #+#             */
/*   Updated: 2024/04/22 17:35:02 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

long	ft_atoi(const char *str)
{
	int				negatif;
	int				i;
	unsigned long	nb;

	nb = 0;
	negatif = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * negatif);
}

void	atobits(int pid, char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if ((c & (1 << i)))
			signal(SIGUSR1, pid);
		else
			signal(SIGUSR2, pid);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	int i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			atobits(pid, argv[2][i]);
			i++;
		}
	}
	else
		return (write(2, "Error\n", 6));
	return (0);
}