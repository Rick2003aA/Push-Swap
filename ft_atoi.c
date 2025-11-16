/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:38:32 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/16 13:25:42 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_atoi(const char *nptr, int *error)
{
	long long	n;
	int			countn;

	n = 0;
	countn = 1;
	while ((*nptr == ' ' || (9 <= *nptr && *nptr <= 13)))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			countn = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = (n * 10) + (*nptr - '0');
		if (countn * n > INT_MAX || countn * n < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		nptr++;
	}
	return (countn * n);
}
