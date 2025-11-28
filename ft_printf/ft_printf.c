/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:55 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/28 11:59:03 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pf_parse(t_pf *st)
{
	const char	*fmt;
	char		next;

	fmt = st->fmt;
	next = fmt[st->i + 1];
	if (!next)
	{
		st->written = -1;
		st->i += 1;
		st->spec = 0;
		return ;
	}
	if (next == 'c' || next == 's' || next == 'd' || next == 'i'
		|| next == 'u' || next == 'x' || next == 'X'
		|| next == 'p' || next == '%')
	{
		st->spec = fmt[st-> i + 1];
		st->i += 2;
		return ;
	}
	pf_putc(st, '%');
	st->spec = next;
	st->i += 2;
}

void	pf_dispatch(t_pf *st)
{
	if (st->spec == 0)
		return ;
	else if (st->spec == 'c')
		pf_print_c(st);
	else if (st->spec == 'd' || st->spec == 'i')
		pf_print_di(st);
	else if (st->spec == 's')
		pf_print_s(st);
	else if (st->spec == 'u')
		pf_print_u(st);
	else if (st->spec == 'x' || st->spec == 'X')
		pf_print_x(st);
	else if (st->spec == 'p')
		pf_print_p(st);
	else if (st->spec == '%')
		pf_putc(st, '%');
	else if (st->spec)
		pf_putc(st, st->spec);
}

int	ft_printf(const char *fmt, ...)
{
	t_pf		st;

	va_start(st.ap, fmt);
	if (!fmt)
		return (-1);
	st.fmt = fmt;
	st.i = 0;
	st.written = 0;
	st.spec = 0;
	while (st.fmt[st.i])
	{
		if (st.fmt[st.i] != '%')
			pf_putc(&st, st.fmt[st.i++]);
		else
		{
			pf_parse(&st);
			pf_dispatch(&st);
		}
	}
	if ((int)st.written == -1)
		va_end(st.ap);
	va_end(st.ap);
	return (st.written);
}
