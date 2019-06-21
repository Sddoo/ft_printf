/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:26:10 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/18 16:26:31 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_initargcontent(t_argcontent *argcontent)
{
	argcontent->precision = 0;
	argcontent->width = 0;
	argcontent->hash = 0;
	argcontent->minus = 0;
	argcontent->plus = 0;
	argcontent->zero = 0;
	argcontent->point = 0;
	argcontent->space = 0;
}
