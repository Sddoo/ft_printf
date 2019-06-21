/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:59:34 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 04:46:33 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putplus(t_argcontent *argcontent, long long *arg)
{
	if (*arg < 0 && argcontent->type != 'x' && argcontent->type != 'X' && argcontent->type != 'o')
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
		return (0);
	if (arg == 0)
		return (1);
	res = ft_getusize(arg, 10);
	return (res);
}

int		ft_getargsize(t_argcontent argcontent, long long arg)
{
	int		res;

	res = 0;
	if (argcontent.point && arg == 0 && !argcontent.precision)
		return (0);
	if (arg == 0)
		return (1);
	if (argcontent.type == 'x')
		res = ft_getsize(arg, 8);
	else if (argcontent.type == 'X')
		res = ft_getsize(arg, 16);
	else
		res = ft_getsize(arg, 10);
	return (res);
}
