/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:04 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 01:06:35 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checkargcontent(t_argcontent argcontent)
{
	if (argcontent.type != 'c' && argcontent.type != 's'
	&& argcontent.type != 'p' && argcontent.type != 'd'
	&& argcontent.type != 'i' && argcontent.type != 'o'
	&& argcontent.type != 'u' && argcontent.type != 'x'
	&& argcontent.type != 'X' && argcontent.type != 'f'
	&& argcontent.type != 'O' && argcontent.type != 'D'
	&& argcontent.type != 'U' && argcontent.type != '%')
		return (0);
	if (argcontent.minus && argcontent.zero)
		return (0);
	return (1);
}

int		ft_printf(char *format, ...)
{
	va_list				ap;
	t_argcontent		argcontent;
	long long			i;
	int					res;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			argcontent = ft_parser(format, i);
			i += argcontent.length;
			// if (!ft_checkargcontent(argcontent))
			// {
			// 	ft_fastputstr("error\n");
			// 	return (-1);
			// }
			res += ft_putarg(argcontent, ap);
		}
		else
		{
			ft_putchar(format[i++]);
			res++;
		}
	}
	va_end(ap);
	return (res);
}
