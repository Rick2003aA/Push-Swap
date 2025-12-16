/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:38:32 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/12/08 11:54:08 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_num(const char *nptr, int *error, int countn)
{
	long long	n;

	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = (n * 10) + (*nptr - '0');
		if ((countn == 1 && n > INT_MAX) || (countn == -1 && (-n) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		nptr++;
	}
	if (*nptr != '\0' && !('0' <= *nptr && *nptr <= '9'))
	{
		*error = 1;
		return (0);
	}
	return (n);
}

int	ft_atoi(const char *nptr, int *error)
{
	long long	n;
	int			countn;

	*error = 0;
	n = 0;
	countn = 1;
	while ((*nptr == ' ' || (9 <= *nptr && *nptr <= 13)))
		nptr++;
	if (*nptr == '-')
	{
		if (*nptr == '-')
			countn = -1;
		nptr++;
	}
	if (!('0' <= *nptr && *nptr <= '9'))
	{
		*error = 1;
		return (0);
	}
	n = make_num(nptr, error, countn);
	if (*error)
		return (0);
	return (countn * n);
}
