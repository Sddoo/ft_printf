/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:04:09 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/18 16:28:56 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_getbeforefloat(t_argcontent argcontent, int size)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(argcontent.width - size + 1)))
		return (NULL);
	if (argcontent.zero)
		while (argcontent.width - size > 0)
		{
			res[i++] = '0';
			size++;
		}
	else
		while (argcontent.width - size > 0)
		{
			res[i++] = ' ';
			size++;
		}
	res[i] = '\0';
	return (res);
}

char	*ft_beforefloat(t_argcontent argcontent, long double arg)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = 1;
	if (!argcontent.precision && !argcontent.point)
		size += 6;
	else if (argcontent.precision == 0)
		size--;
	size += ft_getfloatsize_l(arg) + argcontent.precision;
	if (!argcontent.minus && size < argcontent.width)
		res = ft_getbeforefloat(argcontent, size);
	else
		return ("");
	return (res);
}

int		ft_putf(t_argcontent argcontent, double arg)
{
	char		*res;
	int			size;

	size = 0;
	res = ft_strjoin(ft_beforefloat(argcontent, arg), ft_ftoa(argcontent, arg));
	ft_putstr(res);
	if (argcontent.minus)
	{
		size = 1;
		if (!argcontent.precision && !argcontent.point)
			size += 6;
		if (argcontent.precision == 0)
			size--;
		size += ft_getfloatsize_l(arg) + argcontent.precision;
		if (argcontent.minus && argcontent.width - size > 0)
			while (argcontent.width - size > 0)
			{
				ft_putchar(' ');
				size++;
			}
	}
	else
		size += ft_strlen(res);
	return (size);
}

char	*ft_ftoa(t_argcontent ac, long double arg)
{
	long double	h;
	long double	leftpart;
	char		*res;

	h = 0.0;
	leftpart = (__int128_t)arg;
	arg -= leftpart;
	res = ft_strjoin(ft_itoa_big(leftpart), ft_getfloatpart_r(ac, arg));
	return (res);
}

int		ft_putlf(t_argcontent argcontent, long double arg)
{
	char		*res;
	int			size;

	size = 0;
	res = ft_strjoin(ft_beforefloat(argcontent, arg), ft_ftoa(argcontent, arg));
	ft_putstr(res);
	if (argcontent.minus)
	{
		size = 1;
		if (!argcontent.precision && !argcontent.point)
			size += 6;
		if (argcontent.precision == 0)
			size--;
		size += ft_getfloatsize_l(arg) + argcontent.precision;
		if (argcontent.minus && argcontent.width - size > 0)
			while (argcontent.width - size > 0)
			{
				ft_putchar(' ');
				size++;
			}
	}
	else
		size += ft_strlen(res);
	return (size);
}
