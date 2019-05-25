/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcsp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:41:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/25 18:21:07 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_putstring(t_argcontent argcontent, char *arg)
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
}

void	ft_putp(t_argcontent argcontent, long long arg)
{
	char		*res;
	long long	i;

	res = ft_gethexstr(arg, 'a');
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
