/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:04:09 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/15 13:58:59 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getfloatsize_l(float arg)
{
	int		res;

	res = 0;
	while (arg >= 1)
	{
		res++;
		arg /= 10;
	}
	res = (!res) ? 1 : res;
	return(res);
}

char	ft_getfloatchar_r(float *arg)
{
	int		h;

	*arg *= 10;
	h = (int)*arg;
	*arg -= h;
	return (h + '0');
}

char	*ft_getfloatpart_r(t_argcontent argcontent, float arg)
{
	char	*res;
	int		i;
	int		rightsize;

	if (!argcontent.precision && argcontent.point && !argcontent.hash)
		return ("");
	i = 0;
	rightsize = (argcontent.precision) ? argcontent.precision : 6;
	if (!(res = (char*)malloc(rightsize + 2)))
		return(0);
	res[i++] = '.';
	if (argcontent.hash)
	{
		res[i] = '\0';
		return (res);
	}
	res[rightsize + 1] = '\0';
	while (rightsize--)
	{
		res[i] = ft_getfloatchar_r(&arg);
		i++;
	}
	return(res);
}

char	*ft_beforefloat(t_argcontent argcontent, float arg)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	if (!argcontent.precision && !argcontent.point)
		argcontent.precision = 7; // 6 + 1 за точку и Сашку
	size = ft_getfloatsize_l(arg) + argcontent.precision;
	if (!argcontent.minus && size < argcontent.width)
	{
		if (!(res = (char*)malloc(argcontent.width - size + 1)))
			return(NULL);
		if (argcontent.zero)
			while (argcontent.width - size > 0)
			{
				res[i++] = '0';
				size++;
			}
		else
			while (argcontent.width - size - 1 > 0)
			{
				res[i++] = ' ';
				size++;
			}
		return(res);
	}
	else
		return("");
}

char	*ft_ftoa(t_argcontent ac, float arg)
{
	float	h;
	float	leftpart;
	char	*res;

	h = 0.0;
	leftpart = (__int128_t)arg;
	arg -= leftpart;
	res = ft_strjoin(ft_itoa_big(leftpart), ft_getfloatpart_r(ac, arg));
	return(res);
}

int		ft_putf(t_argcontent argcontent, float arg)
{
	char	*res;
	int		size;

	size = 0;
	res = ft_strjoin(ft_beforefloat(argcontent, arg), ft_ftoa(argcontent, arg));
	ft_putstr(res);
	if (!argcontent.precision && !argcontent.point)
		argcontent.precision = 7; // 6 + 1 за точку и Сашку
	if (argcontent.minus && argcontent.width - size > 0)
		while (argcontent.width - size > 0)
		{
			ft_putchar(' ');
			size++;
		}
	return (ft_strlen(res) + size);
}
