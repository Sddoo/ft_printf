/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:01:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/24 20:48:13 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_big(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr_big(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putc(t_argcontent argcontent, long long arg)
{
	long long i;

	i = 0;
	if (argcontent.minus)
		ft_putchar(arg);
	while (i++ < argcontent.width - 1)
		ft_putchar(' ');
	if (!argcontent.minus)
		ft_putchar(arg);
}

int		ft_putstring(t_argcontent argcontent, char *arg)
{
	long long	i;
	char		*newstr;

	i = 0;
	newstr = ft_strdup(arg);
	if (argcontent.length > argcontent.precision && argcontent.point)
		newstr[argcontent.precision] = '\0';
	i += ft_strlen(newstr);
	if (argcontent.minus)
		ft_putstr(newstr);
	while (i++ < argcontent.width)
		ft_putchar(' ');
	if (!argcontent.minus)
		ft_putstr(newstr);
	return (1);
}

char	*ft_gethexstr(long long arg)
{
	char		*res;
	long long	help;
	int			i;

	help = arg;
	i = 0;
	while (arg)
	{
		arg /= 16;
		i++;
	}
	if (!(res = (char*)malloc(i + 1)))
		exit(0);
	res[i--] = '\0';
	while (help)
	{
		if (help % 16 >= 10)
			res[i] = 'a' + help % 16 % 10;
		else
			res[i] = help % 16 + '0';
		help /= 16;
		i--;
	}
	return (res);
}

void	ft_putp(t_argcontent argcontent, long long arg)
{
	char		*res;
	long long	i;

	res = ft_gethexstr(arg);
	i = ft_strlen(res) + 2;
	if (argcontent.minus)
	{
		ft_putstr("0x");
		ft_putstr(res);
	}
	while (i < argcontent.width)
	{
		ft_putchar(' ');
		i++;
	}
	if (!argcontent.minus)
	{
		ft_putstr("0x");
		ft_putstr(res);
	}
}

void	ft_putminusd(t_argcontent argcontent)
{

}

void	ft_putd(t_argcontent argcontent, long long arg)
{
	long long	i;
	long long	size;
	long long	help;

	i = 0;
	size = 0;
	help = arg;

	while (help)
	{
		help /= 10;
		size++;
	}

	if (argcontent.minus)
	{
		while(i < argcontent.precision - size)
		{
			ft_putchar('0');
			i++;
		}
	}

	// else if (argcontent.zero) // в таком случае добавить !argcontent.zero в нижний иф
	// {
	// 	while (argcontent.precision && i < argcontent.width - argcontent.precision && i < argcontent.width - size)
	// 	{
	// 		ft_putchar(' ');
	// 		i++;
	// 	}
	// 	i = 0;
	// 	while ((!argcontent.precision && i < argcontent.width - size) || i < argcontent.precision - size)
	// 	{
	// 		ft_putchar('0');
	// 		i++;
	// 	}
	// }

	else if (argcontent.zero && !argcontent.precision)
	{
		if (arg < 0)
		{
			argcontent.width--;
			ft_putchar('-');
			arg *= -1;
		}
		while (i < argcontent.width - size)
		{
			ft_putchar('0');
			i++;
		}
	}

	else if (!argcontent.minus)
	{
		if (arg < 0)
			argcontent.width--;
		while (i < argcontent.width - argcontent.precision && i < argcontent.width - size)
		{
			ft_putchar(' ');
			i++;
		}
		i = 0;
		while (i < argcontent.precision - size)
		{
			if (arg < 0)
			{
				ft_putchar('-');
				arg *= -1;
			}
			ft_putchar('0');
			i++;
		}
	}

	if (argcontent.plus)
		ft_putchar('+');

	ft_putnbr(arg);

	if (argcontent.minus && i + size < argcontent.width)
		while (i + size < argcontent.width)
		{
			ft_putchar(' ');
			i++;
		}
}

void	ft_putarg(t_argcontent argcontent, va_list ap)
{
	if (argcontent.type == 'c' || argcontent.type == 'd' || argcontent.type == 'i' || argcontent.type == 'p')
		ft_putlong(argcontent, va_arg(ap, long long));
	else if (argcontent.type == 's')
		ft_putstring(argcontent, va_arg(ap, char*));
}

int		ft_putlong(t_argcontent argcontent, long long arg)
{
	if (argcontent.type == 'c')
		ft_putc(argcontent, arg);
	else if (argcontent.type == 'd' || argcontent.type == 'i')
		ft_putd(argcontent, arg);
	else if (argcontent.type == 'p')
		ft_putp(argcontent, arg);
	return (1);
}
