/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:01:52 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/25 17:59:07 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putarg(t_argcontent argcontent, va_list ap)
{
	if (argcontent.type == 'c' || argcontent.type == 'd' ||
		argcontent.type == 'i' || argcontent.type == 'p' ||
		argcontent.type == 'u' || argcontent.type == 'o' ||
		argcontent.type == 'x' || argcontent.type == 'X')
		ft_putlong(argcontent, va_arg(ap, long long));
	else if (argcontent.type == 's')
		ft_putstring(argcontent, va_arg(ap, char*));
}

int		ft_putlong(t_argcontent argcontent, long long arg)
{
	if (argcontent.type == 'c')
		ft_putc(argcontent, arg);
	else if (argcontent.type == 'd' || argcontent.type == 'i'||
	argcontent.type == 'u' || argcontent.type == 'o' ||
	argcontent.type == 'x' || argcontent.type == 'X')
		ft_putd(argcontent, arg);
	else if (argcontent.type == 'p')
		ft_putp(argcontent, arg);
	return (1);
}
