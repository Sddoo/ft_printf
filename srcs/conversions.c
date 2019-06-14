/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:49:06 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 20:01:32 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_ubig(unsigned long long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr_ubig(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

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

char	*ft_gethexstr(long long arg, char c, char *modificator)
{
	char				*res;
	int					i;
	unsigned long long	help;
	unsigned long long	uarg;

	i = 0;
	uarg = arg;
	if (!arg)
		return ("0");
	else if (arg < 0 && !ft_strcmp(modificator, "hh"))
		uarg = 255 + arg + 1;
	else if (arg < 0 && ft_strcmp(modificator, "ll") && ft_strcmp(modificator, "l"))
		uarg = 4294967295 + arg + 1;
	else if (arg < 0)
		uarg = (unsigned long long)(18446744073709551615U + arg + 1);
	help = uarg;
	while (uarg)
	{
		uarg /= 16;
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

char	*ft_getoctstr(long long arg, char *modificator)
{
	char				*res;
	unsigned long long	uarg;
	unsigned long long	help;
	int					i;

	i = 0;
	if (!arg)
		return ("0");
	if (arg < 0 && !ft_strcmp(modificator, "hh"))
		uarg = 255 + arg + 1;
	else if (arg < 0 && ft_strcmp(modificator, "ll") && ft_strcmp(modificator, "l"))
		uarg = 4294967295 + arg + 1;
	else
		uarg = (unsigned long long)(18446744073709551615U + arg + 1);
	help = uarg;
	while (uarg)
	{
		uarg /= 8;
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

long long int		ft_itoa_size(long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoares_big(char *str, long long i, long long n)
{
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa_big(long long nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ft_itoa_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
	{
		str = NULL;
		return (NULL);
	}
	str = ft_itoares_big(str, i, n);
	return (str);
}

void ft_fastputstr(char *str)
{
	char *start = str;
	while (*str) str++;
	write(1, start, str - start);
}
