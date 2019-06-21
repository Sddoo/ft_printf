/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:42:59 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 05:47:06 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putminusd_flag(t_argcontent argcontent, long long *i, long long size,
					long long *arg)
{
	if (*arg < 0 && argcontent.type != 'x'
	&& argcontent.type != 'X' && argcontent.type != 'o')
	{
		*arg *= -1;
		ft_putchar('-');
		(*i)++;
	}
	else if (argcontent.plus && *arg >= 0 && argcontent.type != 'u')
		ft_putchar('+');
	ft_puthashd(argcontent, i, arg);
	while (*i < argcontent.precision - size)
	{
		ft_putchar('0');
		(*i)++;
	}
	if (argcontent.plus && *arg >= 0)
		(*i)++;
}

void	ft_putzerod_flag(t_argcontent argcontent, long long *i,
					long long size, long long *arg)
{
	long long	h;

	h = 0;
	if (*arg < 0 || argcontent.plus || ((argcontent.precision <= size
	&& argcontent.hash && argcontent.type == 'o') && *arg))
		argcontent.width--;
	if (argcontent.precision <= size && argcontent.hash
	&& (argcontent.type == 'x' || argcontent.type == 'X') && *arg)
		argcontent.width -= 2;
	while (argcontent.point && *i < argcontent.width -
	argcontent.precision && *i < argcontent.width - size)
	{
		ft_putchar(' ');
		(*i)++;
	}
	ft_puthashd(argcontent, &h, arg);
	ft_putplus(&argcontent, arg);
	size -= h;
	if (argcontent.space)
		size++;
	while ((!argcontent.point && h < argcontent.width - size) ||
	h < argcontent.precision - size)
	{
		ft_putchar('0');
		h++;
	}
	*i += h;
}

void	ft_putwpd_flags(t_argcontent argcontent, long long *i,
				long long size, long long *arg)
{
	long long	h;

	h = 0;
	if (*arg < 0 || argcontent.plus
	|| ((argcontent.hash && argcontent.type == 'o') && *arg))
		argcontent.width--;
	if (argcontent.hash && (argcontent.type == 'x'
	|| argcontent.type == 'X') && *arg)
		argcontent.width -= 2;
	while (*i < argcontent.width - argcontent.precision
	&& *i < argcontent.width - size)
	{
		ft_putchar(' ');
		(*i)++;
	}
	ft_puthashd(argcontent, &h, arg);
	ft_putplus(&argcontent, arg);
	if (argcontent.type != 'o')
		size -= h;
	while (h < argcontent.precision - size)
	{
		ft_putchar('0');
		h++;
	}
	*i += h;
}

void	ft_inittype(t_argcontent argcontent,
unsigned long long *uarg, long long *arg)
{
	*uarg = *arg;
	if ((((argcontent.type == 'x' || argcontent.type == 'X') && (*arg <= -4294967296 || *arg > 4294967295)))
	&& (!ft_strcmp(argcontent.modificator, "hh") || !ft_strcmp(argcontent.modificator, "h") || !ft_strcmp(argcontent.modificator, "")))
		*arg = (int)*arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, ""))
		*uarg = (unsigned int)*arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "l"))
		*uarg = (unsigned long)*arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "h"))
		*uarg = (unsigned short)*arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "hh"))
		*uarg = (unsigned char)*arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "ll"))
		*uarg = (unsigned long long)(18446744073709551615U + *arg + 1);
	else if (!ft_strcmp(argcontent.modificator, "ll"))
		*arg = (long long int)*arg;
	else if (!ft_strcmp(argcontent.modificator, "h"))
		*arg = (short)*arg;
	else if (!ft_strcmp(argcontent.modificator, "hh"))
		*arg = (char)*arg;
	else if (((argcontent.type == 'd' || argcontent.type == 'i') && (*arg > 2147483647 || *arg <= -2147483648)
	&& (!ft_strcmp(argcontent.modificator, "hh") || !ft_strcmp(argcontent.modificator, "h") || !ft_strcmp(argcontent.modificator, ""))))
		*arg = (int)*arg;
}

void	ft_inithex(t_argcontent *argcontent, char **hex, long long arg)
{
	if (((argcontent->type == 'x' || argcontent->type == 'X')
	&& !argcontent->precision && argcontent->point && !arg)
	|| (argcontent->type == 'o' && !argcontent->hash
	&& !argcontent->precision && argcontent->point && !arg))
		*hex = NULL;
	else if (argcontent->type == 'o' && arg == 0
	&& argcontent->hash && !argcontent->point)
	{
		argcontent->hash = 0;
		*hex = ft_strdup("0");
	}
	else if (argcontent->type == 'x')
		*hex = ft_gethexstr(arg, 'a', argcontent->modificator);
	else if (argcontent->type == 'X')
		*hex = ft_gethexstr(arg, 'A', argcontent->modificator);
	else if (argcontent->type == 'o')
		*hex = ft_getoctstr(arg, argcontent->modificator);
}

int		ft_initsize(t_argcontent argcontent, long long *arg,
unsigned long long *uarg, char *hex)
{
	int		res;

	if (argcontent.type == 'u')
		res = ft_getuargsize(argcontent, *uarg);
	else if ((argcontent.type == 'x' || argcontent.type == 'X'
	|| argcontent.type == 'o') && hex)
		res = ft_strlen(hex);
	else
		res = ft_getargsize(argcontent, *arg);
	return (res);
}

void	ft_putflags(t_argcontent argcontent, long long *i,
int size, long long *arg)
{
	if (argcontent.space && !argcontent.plus && *arg >= 0 && argcontent.type != 'u')
	{
		ft_putchar(' ');
		(*i)++;
	}
	if (argcontent.minus)
		ft_putminusd_flag(argcontent, i, size, arg);
	else if (argcontent.zero)
		ft_putzerod_flag(argcontent, i, size, arg);
	else if (argcontent.width || argcontent.precision)
		ft_putwpd_flags(argcontent, i, size, arg);
	else if (argcontent.hash && *arg)
		ft_puthashd(argcontent, i, arg);
	else if (argcontent.plus && *arg >= 0 && argcontent.type != 'u')
		ft_putchar('+');
}

void	ft_putmain(t_argcontent argcontent, unsigned long long uarg,
long long arg, char *hex)
{
	if ((argcontent.type == 'x' || argcontent.type == 'X'
	|| argcontent.type == 'o') && hex)
		ft_fastputstr(hex);
	else if (argcontent.point && arg == 0 && !argcontent.precision)
		ft_putstr("");
	else if (argcontent.type != 'u')
		ft_putnbr_big(arg);
	else
		ft_putnbr_ubig(uarg);
}

void	ft_putafterspaces(t_argcontent argcontent, long long size, long long *i)
{
	if (argcontent.minus && *i + size < argcontent.width)
		while (*i + size < argcontent.width)
		{
			ft_putchar(' ');
			(*i)++;
		}
}

int		ft_getres(t_argcontent argcontent, long long size, long long arg,
unsigned long long uarg)
{
	if (argcontent.type == 'x' || argcontent.type == 'X'
	|| argcontent.type == 'o')
		return (size);
	else if (argcontent.type == 'u')
		return (ft_getuargsize(argcontent, uarg));
	else
		return (ft_getargsize(argcontent, arg));
}

int		ft_putd(t_argcontent argcontent, long long arg)
{
	long long			i;
	long long			size;
	int					res;
	unsigned long long	uarg;
	char				*hex;

	i = 0;
	size = 0;
	res = 0;
	hex = NULL;
	ft_inittype(argcontent, &uarg, &arg);
	ft_inithex(&argcontent, &hex, arg);
	if (argcontent.type == 'u' && arg < 0)
		arg *= -1;
	if (((arg < 0 || argcontent.plus) && !argcontent.minus)
	&& argcontent.type != 'x' && argcontent.type != 'X'
	&& argcontent.type != 'o' && argcontent.type != 'u')
		res++;
	size = ft_initsize(argcontent, &arg, &uarg, hex);
	ft_putflags(argcontent, &i, size, &arg);
	ft_putmain(argcontent, uarg, arg, hex);
	ft_putafterspaces(argcontent, size, &i);
	res += i + ft_getres(argcontent, size, arg, uarg);
	return (res);
}
