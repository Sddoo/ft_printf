/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:42:59 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 19:37:00 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putzerod(t_argcontent *argcontent, long long *i, long long *arg)
{
	if (*arg < 0)
	{
		ft_putchar('-');
		*arg *= -1;
		argcontent->plus = 0;
	}
	else if (argcontent->plus)
	{
		ft_putchar('+');
		argcontent->plus = 0;
	}
	ft_putchar('0');
	(*i)++;
}

void	ft_puthashd(t_argcontent argcontent, long long *i, long long *arg)
{
	if (argcontent.hash && argcontent.type == 'o' && *arg)
	{
		ft_putchar('0');
		(*i)++;
	}
	else if (argcontent.hash && argcontent.type == 'x' && *arg)
	{
		ft_putstr("0x");
		*i += 2;
	}
	else if (argcontent.hash && argcontent.type == 'X' && *arg)
	{
		ft_putstr("0X");
		*i += 2;
	}
}

int		ft_getuargsize(t_argcontent argcontent, unsigned long long arg)
{
	int		res;
	
	res = 0;
	if (argcontent.point && arg == 0 && !argcontent.precision)
		return(0);
	if (arg == 0)
		return(1);
	while (arg)
	{
		arg /= 10;
		res++;
	}
	return (res);
}

int		ft_getargsize(t_argcontent argcontent, long long arg)
{
	int		res;
	
	res = 0;
	if (argcontent.point && arg == 0 && !argcontent.precision)
		return(0);
	if (arg == 0)
		return(1);
	if (argcontent.type == 'x')
		while (arg)
		{
			arg /= 8;
			res++;
		}
	else if (argcontent.type == 'X')
		while (arg)
		{
			arg /= 16;
			res++;
		}
	else
		while (arg)
		{
			arg /= 10;
			res++;
		}
	return (res);
}

void	ft_putminusd_flag(t_argcontent argcontent, long long *i, long long size,
					long long *arg)
{
	if (*arg < 0 && argcontent.type != 'x' && argcontent.type != 'X' && argcontent.type != 'o')
	{
		*arg *= -1;
		ft_putchar('-');
		(*i)++;
	}
	else if (argcontent.plus && *arg >= 0)
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
	size -= h;
	while ((!argcontent.point && h < argcontent.width - size) ||
	h < argcontent.precision - size)
		ft_putzerod(&argcontent, &h, arg);
	*i += h;
}

void	ft_putwpd_flags(t_argcontent argcontent, long long *i,
				long long size, long long *arg)
{
	long long	h;

	h = 0;
	if (*arg < 0 || argcontent.plus || ((argcontent.hash && argcontent.type == 'o') && *arg))
		argcontent.width--;
	if (argcontent.hash && (argcontent.type == 'x' || argcontent.type == 'X') && *arg)
		argcontent.width -= 2;
	while (*i < argcontent.width - argcontent.precision && *i < argcontent.width - size)
	{
		ft_putchar(' ');
		(*i)++;
	}
	ft_puthashd(argcontent, &h, arg);
	size -= h;
	while (h < argcontent.precision - size)
		ft_putzerod(&argcontent, &h, arg);
	*i += h;
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
	uarg = arg;
	
	if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "")) // сделать обработку ll, hh...
		uarg = (unsigned int)arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "l"))
		uarg = (unsigned long)arg;
	else if (argcontent.type == 'u' && !ft_strcmp(argcontent.modificator, "ll"))
		uarg = (unsigned long long)(18446744073709551615U + arg + 1);
	else if ((argcontent.type == 'd' || argcontent.type == 'o') && !ft_strcmp(argcontent.modificator, "ll"))
		arg = (long long int)arg;
	else if ((argcontent.type == 'd' || argcontent.type == 'o') && !ft_strcmp(argcontent.modificator, "h"))
		arg = (short)arg;
	else if ((argcontent.type == 'd' || argcontent.type == 'o') && !ft_strcmp(argcontent.modificator, "hh"))
		arg = (char)arg;

	if (((argcontent.type == 'x' || argcontent.type == 'X') && !argcontent.precision && argcontent.point && !arg) ||
	(argcontent.type == 'o' && !argcontent.hash && !argcontent.precision && argcontent.point && !arg))
		hex = NULL;
	else if (argcontent.type == 'o' && arg == 0 && argcontent.hash && !argcontent.point)
	{
		argcontent.hash = 0;
		hex = ft_strdup("0");
	}
	else if (argcontent.type == 'x')
		hex = ft_gethexstr(arg, 'a', argcontent.modificator);
	else if (argcontent.type == 'X')
		hex = ft_gethexstr(arg, 'A', argcontent.modificator);
	else if (argcontent.type == 'o')
		hex = ft_getoctstr(arg, argcontent.modificator);

	if (argcontent.type == 'u' && arg < 0)
		arg *= -1;
	if (((arg < 0 || argcontent.plus) && !argcontent.minus) && argcontent.type != 'x' && argcontent.type != 'X' && argcontent.type != 'o')
		res++;
	if (argcontent.type == 'u')
		size = ft_getuargsize(argcontent, uarg);
	else if ((argcontent.type == 'x' || argcontent.type == 'X' || argcontent.type == 'o') && hex)
		size = ft_strlen(hex);
	else
		size = ft_getargsize(argcontent, arg);

	if (argcontent.space && !argcontent.plus && arg >= 0)
	{
		ft_putchar(' ');
		i++;
	}
	if (argcontent.minus)
		ft_putminusd_flag(argcontent, &i, size, &arg);
	else if (argcontent.zero)
		ft_putzerod_flag(argcontent, &i, size, &arg);
	else if (argcontent.width || argcontent.precision)
		ft_putwpd_flags(argcontent, &i, size, &arg);
	else if (argcontent.hash && arg)
		ft_puthashd(argcontent, &i, &arg);
	else if (argcontent.plus && arg >= 0)
		ft_putchar('+');

	if ((argcontent.type == 'x' || argcontent.type == 'X' || argcontent.type == 'o') && hex)
		ft_fastputstr(hex);
	else if (argcontent.point && arg == 0 && !argcontent.precision)
		ft_putstr("");
	else if (argcontent.type != 'u')
		ft_putnbr_big(arg);
	else
		ft_putnbr_ubig(uarg);

	if (argcontent.minus && i + size < argcontent.width)
		while (i + size < argcontent.width)
		{
			ft_putchar(' ');
			i++;
		}
	if (argcontent.type == 'x' || argcontent.type == 'X' || argcontent.type == 'o')
		res += i + size;
	else if (argcontent.type == 'u')
		res += i + ft_getuargsize(argcontent, uarg);
	else
		res += i + ft_getargsize(argcontent, arg);
	return (res);
}
