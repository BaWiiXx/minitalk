/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:27:28 by bdany             #+#    #+#             */
/*   Updated: 2024/05/06 11:17:52 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(int s, long m)
{
	int	check;

	check = 2;
	if (m * s < -2147483648 || m * s > 2147483647)
		check = 0;
	return (check);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		s;
	long	m;

	i = 0;
	s = 1;
	m = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		m = m * 10 + (nptr[i] - '0');
		if (is_overflow(s, m) == 0)
			return (0);
		i++;
	}
	if ((size_t)i != ft_strlen(nptr))
		return (0);
	return (m * s);
}
