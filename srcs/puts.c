/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:01:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 05:24:05 by hfrankly         ###   ########.fr       */
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
		return (-1);
	if (argcontent.minus)
		res[i++] = '%';
	while (i < argcontent.width)
	{
		if (argcontent.zero && !argcontent.minus)
			res[i] = '0';
		else
			res[i] = ' ';
		i++;
	}
	if (!argcontent.minus)
		res[size - 1] = '%';
	res[size] = '\0';
	ft_fastputstr(res);
	return (size);
}

int		ft_putarg(t_argcontent ac, va_list ap)
{
	if (ac.type == 'c' || ac.type == 'd' ||
		ac.type == 'i' || ac.type == 'p' ||
		ac.type == 'u' || ac.type == 'o' ||
		ac.type == 'x' || ac.type == 'X')
	{
		if (!(ft_strcmp(ac.modificator, "ll")))
			return (ft_putlong(ac, va_arg(ap, long long)));
		else if (!ft_strcmp(ac.modificator, "l") || ac.type == 'p')
			return (ft_putlong(ac, va_arg(ap, long)));
		else if (!ft_strcmp(ac.modificator, "j"))
			return (ft_putlong(ac, va_arg(ap, intmax_t)));
		else if (!ft_strcmp(ac.modificator, "z"))
			return (ft_putlong(ac, va_arg(ap, ssize_t)));
		else if (!ft_strcmp(ac.modificator, "ll") && ac.type == 'u')
			return (ft_putlong(ac, va_arg(ap, unsigned long long)));
		else if (!ft_strcmp(ac.modificator, "")
	|| !ft_strcmp(ac.modificator, "hh") || !ft_strcmp(ac.modificator, "h"))
			return (ft_putlong(ac, va_arg(ap, long long)));
	}
	else if (ac.type == 's')
		return (ft_putstring(ac, va_arg(ap, char*)));
	else if (ac.type == 'f' && ft_strcmp(ac.modificator, "L"))
		return (ft_putf(ac, va_arg(ap, double)));
	else if (ac.type == 'f')
		return (ft_putlf(ac, va_arg(ap, long double)));
	else if (ac.type == '%')
		return (ft_putpercent(ac));
	return (-1);
}

int		ft_putlong(t_argcontent argcontent, long long arg)
{
	if (argcontent.type == 'c')
		return (ft_putc(argcontent, arg));
	else if (argcontent.type == 'd' || argcontent.type == 'i' ||
	argcontent.type == 'u' || argcontent.type == 'o' ||
	argcontent.type == 'x' || argcontent.type == 'X')
		return (ft_putd(argcontent, arg));
	else if (argcontent.type == 'p')
		return (ft_putp(argcontent, arg));
	return (-1);
}
