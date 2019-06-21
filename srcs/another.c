/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:49:06 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 03:01:15 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putnbr_ubig(unsigned long long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr_ubig(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void			ft_putnbr_big(long long n)
{
	if (n / 10 == -922337203685477580 && n % 10 == -8)
	{
		ft_fastputstr("-9223372036854775808");
		return;
	}
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

char			*ft_gethexstr(long long arg, char c, char *modificator)
{
	char				*res;
	int					i;
	unsigned long long	help;
	unsigned long long	uarg;

	i = 0;
	if (!arg)
		return ("0");
	ft_inituarg(arg, &uarg, modificator);
	help = uarg;
	i = ft_getusize(uarg, 16);
	if (!(res = (char*)malloc(i + 1)))
		exit(0);
	res[i--] = '\0';
	while (help)
	{
		if (help % 16 >= 10)
			res[i] = c + help % 16 % 10;
		else
			res[i] = help % 16 + '0';
		help /= 16;
		i--;
	}
	return (res);
}

char			*ft_getoctstr(long long arg, char *modificator)
{
	char				*res;
	unsigned long long	uarg;
	unsigned long long	help;
	int					i;

	i = 0;
	if (!arg)
		return ("0");
	ft_inituarg(arg, &uarg, modificator);
	help = uarg;
	i = ft_getusize(uarg, 8);
	if (!(res = (char*)malloc(i + 1)))
		exit(0);
	res[i--] = '\0';
	while (help)
	{
		res[i] = help % 8 + '0';
		help /= 8;
		i--;
	}
	return (res);
}

long long		ft_atoires_big(const char *str, int i, long long res, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= 9223372036854775807 && sign == -1)
			return (0);
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return (res);
}
