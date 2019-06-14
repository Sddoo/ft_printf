/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:01:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 20:00:00 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putpercent(t_argcontent argcontent)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = (argcontent.width) ? argcontent.width : 1;
	if (!(res = (char*)malloc(size + 1)))
		return(-1);
	if (argcontent.minus)
		res[i++] = '%';
	while (i < argcontent.width)
	{
		if (argcontent.zero)
			res[i] = '0';
		else
			res[i] = ' ';
		i++;		
	}
	if (!argcontent.minus)
		res[size - 1] = '%';
	res[size] = '\0';
	ft_fastputstr(res);
	return(size);
}

int		ft_putarg(t_argcontent argcontent, va_list ap)
{
	if (argcontent.type == 'c' || argcontent.type == 'd' ||
		argcontent.type == 'i' || argcontent.type == 'p' ||
		argcontent.type == 'u' || argcontent.type == 'o' ||
		argcontent.type == 'x' || argcontent.type == 'X')
		{
			if (!(ft_strcmp(argcontent.modificator, "ll")))
				return(ft_putlong(argcontent, va_arg(ap, long long)));
			else if (!(ft_strcmp(argcontent.modificator, "l")))
				return(ft_putlong(argcontent, va_arg(ap, long)));
			else if (!(ft_strcmp(argcontent.modificator, "ll")) && argcontent.type == 'u')
				return(ft_putlong(argcontent, va_arg(ap, unsigned long long)));
			else
				return(ft_putlong(argcontent, va_arg(ap, int)));
		}
	else if (argcontent.type == 's')
		return(ft_putstring(argcontent, va_arg(ap, char*)));
	else if (argcontent.type == 'f')
		return(ft_putf(argcontent, va_arg(ap, double)));
	else if (argcontent.type == '%')
		return(ft_putpercent(argcontent));
	return (-1);
}

int		ft_putlong(t_argcontent argcontent, long long arg)
{
	if (argcontent.type == 'c')
		return(ft_putc(argcontent, arg));
	else if (argcontent.type == 'd' || argcontent.type == 'i'||
	argcontent.type == 'u' || argcontent.type == 'o' ||
	argcontent.type == 'x' || argcontent.type == 'X')
		return(ft_putd(argcontent, arg));
	else if (argcontent.type == 'p')
		return(ft_putp(argcontent, arg));
	return (-1);
}
