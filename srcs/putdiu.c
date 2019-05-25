/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdiu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:42:59 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/25 19:43:42 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putzeroesd(t_argcontent argcontent, long long *i, long long *arg)
{
	if (*arg < 0)
	{
		ft_putchar('-');
		*arg *= -1;
		argcontent.plus = 0;
	}
	else if (argcontent.plus)
	{
		ft_putchar('+');
		argcontent.plus = 0;
	}
	ft_putchar('0');
	(*i)++;
}

void	ft_puthashd(t_argcontent argcontent, long long *i)
{
	if (argcontent.hash && argcontent.type == 'o')
	{
		ft_putchar('0');
		if (argcontent.point)
			(*i)++;
	}
	else if (argcontent.hash && argcontent.type == 'x')
		ft_putstr("0x");
	else if (argcontent.hash && argcontent.type == 'X')
		ft_putstr("0X");
}

int		ft_getnmbsize(t_argcontent argcontent, long long arg)
{
	long long res;
	
	res = 0;
	if (argcontent.type != 'x' && argcontent.type != 'X')
		while (arg)
		{
			arg /= 10;
			res++;
		}
	else
		while (arg)
		{
			arg /= 16;
			res++;
		}
	return (res);
}

void	ft_putminusd_flag(t_argcontent argcontent, long long *i, long long size,
					long long *arg)
{
	if (*arg < 0)
	{
		*arg *= -1;
		ft_putchar('-');
	}
	ft_puthashd(argcontent, i);
	while (*i < argcontent.precision - size)
	{
		ft_putchar('0');
		(*i)++;
	}
	if ((argcontent.precision || argcontent.width) && (argcontent.type == 'x' || argcontent.type == 'X')) //дикий костыль
		*i += 2;
}

void	ft_putzerod_flag(t_argcontent argcontent, long long *i,
					long long size, long long *arg)
{
	if (*arg < 0 || argcontent.plus || (argcontent.precision <= size && argcontent.hash && argcontent.type == 'o'))
		argcontent.width--;
	else if (argcontent.type == 'x' || argcontent.type == 'X')
		argcontent.width -= 2;
	while (argcontent.point && *i < argcontent.width -
	argcontent.precision && *i < argcontent.width - size)
	{
		ft_putchar(' ');
		(*i)++;
	}
	(*i) = 0;
	ft_puthashd(argcontent, i);
	while ((!argcontent.point && (*i) < argcontent.width - size) ||
	*i < argcontent.precision - size)
		ft_putzeroesd(argcontent, i, arg);
}

void	ft_putwpd_flags(t_argcontent argcontent, long long *i,
				long long size, long long *arg)
{
	if (*arg < 0 || argcontent.plus || (argcontent.precision <= size && argcontent.hash && argcontent.type == 'o'))
		argcontent.width--;
	else if (argcontent.type == 'x' || argcontent.type == 'X')
		argcontent.width -= 2;
	while (*i < argcontent.width - argcontent.precision &&
	*i < argcontent.width - size)
	{
		ft_putchar(' ');
		(*i)++;
	}
	(*i) = 0;
	ft_puthashd(argcontent, i);
	while (*i < argcontent.precision - size)
		ft_putzeroesd(argcontent, i, arg);
}

void	ft_putd(t_argcontent argcontent, long long arg)
{
	long long	i;
	long long	size;

	i = 0;
	size = 0;
	if (arg < 0 && argcontent.type == 'u') // сделать обработку ll, hh...
		arg = 4294967296 + arg;
	if (argcontent.type == 'o')
		arg = ft_atoi_big(ft_getoctstr(arg));
	size = ft_getnmbsize(argcontent, arg);
	if (argcontent.minus)
		ft_putminusd_flag(argcontent, &i, size, &arg);
	else if (argcontent.zero)
		ft_putzerod_flag(argcontent, &i, size, &arg);
	else if (!argcontent.minus && !argcontent.zero)
		ft_putwpd_flags(argcontent, &i, size, &arg);
	if (argcontent.type == 'x')
		ft_putstr(ft_gethexstr(arg, 'a'));
	else if (argcontent.type == 'X')
		ft_putstr(ft_gethexstr(arg, 'A'));
	else
		ft_putnbr_big(arg);
	if (argcontent.minus && i + size < argcontent.width)
		while (i + size < argcontent.width)
		{
			ft_putchar(' ');
			i++;
		}
}
