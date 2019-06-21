/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:35:21 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 05:46:59 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_inituarg(long long arg,
unsigned long long *uarg, char *modificator)
{
	if (!ft_strcmp(modificator, "z") || !ft_strcmp(modificator, "j") || arg > 0)
		*uarg = arg;
	else if (!ft_strcmp(modificator, "hh"))
		*uarg = 255 + arg + 1;
	else if (!ft_strcmp(modificator, "h"))
		*uarg = 35565 + arg + 1;
	else if (ft_strcmp(modificator, "ll")
	&& ft_strcmp(modificator, "l"))
		*uarg = 4294967295 + arg + 1;
	else
		*uarg = (unsigned long long)(18446744073709551615U + arg + 1);

}

int				ft_getusize(unsigned long long uarg, int b)
{
	int size;

	size = 0;
	while (uarg)
	{
		uarg /= b;
		size++;
	}
	return (size);
}

int				ft_getsize(long long uarg, int b)
{
	int size;

	size = 0;
	while (uarg)
	{
		uarg /= b;
		size++;
	}
	return (size);
}
