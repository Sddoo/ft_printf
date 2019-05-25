/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:49:06 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/25 18:20:06 by hfrankly         ###   ########.fr       */
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

char	*ft_gethexstr(long long arg, char c)
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
			res[i] = c + help % 16 % 10;
		else
			res[i] = help % 16 + '0';
		help /= 16;
		i--;
	}
	return (res);
}

char	*ft_getoctstr(long long arg) // сделать обработку отрицательных чисел
{
	char		*res;
	long long	help;
	int			i;

	help = arg;
	i = 0;
	while (arg)
	{
		arg /= 8;
		i++;
	}
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

long long				ft_atoi_big(const char *str)
{
	long long			res;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = ft_atoires_big(str, i, res, sign);
	return (res * sign);
}
