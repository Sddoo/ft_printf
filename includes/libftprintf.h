/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:04:12 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/25 19:36:31 by hfrankly         ###   ########.fr       */
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
/* --------------- puts.c ---------------- */
void			ft_putarg(t_argcontent argcontent, va_list ap);
int				ft_putlong(t_argcontent argcontent, long long arg);
/* --------------- parser.c ---------------- */
t_argcontent	ft_parser(char *format, long long i);
t_argcontent	ft_getargcontent(char *spec);
void			ft_initargcontent(t_argcontent *argcontent);
void			ft_getflags(t_argcontent *argcontent, char *spec, int *i);
void			ft_getwpm(t_argcontent *argcontent, char *spec, int *i);
/* --------------- putcsp.c ---------------- */
void			ft_putc(t_argcontent argcontent, long long arg);
void			ft_putstring(t_argcontent argcontent, char *arg);
void			ft_putp(t_argcontent argcontent, long long arg);
/* --------------- putdi.c ---------------- */
void			ft_putd(t_argcontent argcontent, long long arg);
void			ft_putminusd_flag(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putzerod_flag(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putwpd_flags(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putzeroesd(t_argcontent argcontent, long long *i, long long *arg);
void			ft_puthashd(t_argcontent argcontent, long long *i);
int				ft_getnmbsize(t_argcontent argcontent, long long arg);
char			*ft_getoctstr(long long arg);
/* --------------- conversions.c ---------------- */
void			ft_putnbr_big(long long n);
char			*ft_gethexstr(long long arg, char c);
long long		ft_atoi_big(const char *str);
long long		ft_atoires_big(const char *str, int i, long long res, int sign);

#endif