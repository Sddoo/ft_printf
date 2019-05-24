/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:04:12 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/24 19:57:36 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef struct s_argcontent	t_argcontent;

struct s_argcontent
{
	int 		hash;
	int 		plus;
	int 		minus;
	int 		zero;
	int 		point;
	long long 	width;
	long long 	precision;
	char 		modificator[3];
	char 		type;
	long long	length;
};

int				ft_printf(char *format, ...);
t_argcontent	ft_parser(char *format, long long i);
void			ft_putarg(t_argcontent argcontent, va_list ap);
int				ft_putlong(t_argcontent argcontent, long long arg);
void			ft_initargcontent(t_argcontent *argcontent);
void			ft_getflags(t_argcontent *argcontent, char *spec, int *i);
void			ft_getwpm(t_argcontent *argcontent, char *spec, int *i);
void			ft_putc(t_argcontent argcontent, long long arg);
void			ft_putd(t_argcontent argcontent, long long arg);

#endif