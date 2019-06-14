/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:04 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 19:59:46 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
