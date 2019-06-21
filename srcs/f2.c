/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:27:54 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/18 16:28:16 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getfloatsize_l(long double arg)
{
	int		res;

	res = 0;
	while (arg >= 1)
	{
		res++;
		arg /= 10;
	}
	res = (!res) ? 1 : res;
	return (res);
}

char	ft_getfloatchar_r(long double *arg)
{
	int		h;

	*arg *= 10;
	h = (int)*arg;
	*arg -= h;
	return (h + '0');
}

char	*ft_getfloatpart_r(t_argcontent argcontent, long double arg)
{
	char	*res;
	int		i;
	int		rightsize;

	if (!argcontent.precision && argcontent.point && !argcontent.hash)
		return ("");
	i = 0;
	rightsize = (argcontent.precision) ? argcontent.precision : 6;
	if (!(res = (char*)malloc(rightsize + 2)))
		return (0);
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
	return (res);
}
