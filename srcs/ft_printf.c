/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:04 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:21 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *format, ...)
{
	va_list				ap;
	t_argcontent		argcontent;
	long long			i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			argcontent = ft_parser(format, i);
			i += argcontent.length;
			ft_putarg(argcontent, ap);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(ap);
	return (1);
}
