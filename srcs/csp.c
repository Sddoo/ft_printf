/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:41:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 04:52:51 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putc(t_argcontent argcontent, long long arg)
{
	long long	i;
	char		c;

	i = 0;
	if (argcontent.zero)
		c = '0';
	else
		c = ' ';
	if (argcontent.minus)
		ft_putchar(arg);
	while (i++ < argcontent.width - 1)
		ft_putchar(c);
	if (!argcontent.minus)
		ft_putchar(arg);
	return (i);
}

int		ft_putstring(t_argcontent argcontent, char *arg)
{
	long long	i;
	char		*newstr;

	if (!arg)
		newstr = ft_strdup("(null)");
	else
		newstr = ft_strdup(arg);
	i = 0;
	if ((long long)ft_strlen(newstr) > argcontent.precision && argcontent.point)
		newstr[argcontent.precision] = '\0';
	i += ft_strlen(newstr);
	if (argcontent.minus)
		ft_putstr(newstr);
	while (i++ < argcontent.width)
		ft_putchar(' ');
	if (!argcontent.minus)
		ft_putstr(newstr);
	return (i - 1);
}

int		ft_putp(t_argcontent argcontent, long long arg)
{
	char		*res;
	long long	i;

	res = ft_gethexstr(arg, 'a', argcontent.modificator);
	i = 2;
	if ((argcontent.point && argcontent.precision) || !argcontent.point)
		i += ft_strlen(res);
	if (argcontent.minus)
	{
		ft_putstr("0x");
		if ((argcontent.point && argcontent.precision) || !argcontent.point)
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
		if ((argcontent.point && argcontent.precision) || !argcontent.point)
			ft_putstr(res);
	}
	return (i);
}
