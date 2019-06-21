/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:29:26 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/20 23:11:35 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

char				*ft_itoares_big(char *str, long long i, long long n)
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

char				*ft_itoa_big(long long nb)
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

void				ft_fastputstr(char *str)
{
	char *start;

	start = str;
	while (*str)
		str++;
	write(1, start, str - start);
}
