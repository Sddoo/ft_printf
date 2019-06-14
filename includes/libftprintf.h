/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:04:12 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 18:41:56 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef struct s_argcontent	t_argcontent;
typedef struct s_float		t_float;

struct s_float
{
	int			sign;
	int 		integer;
	float		floating;
};

struct s_argcontent
{
	int 		hash;
	int 		plus;
	int 		minus;
	int 		zero;
	int 		point;
	int			space;
	long long 	width;
	long long 	precision;
	char 		modificator[3];
	char 		type;
	long long	length;
};

int				ft_printf(char *format, ...);
/* --------------- puts.c ---------------- */
int				ft_putarg(t_argcontent argcontent, va_list ap);
int				ft_putlong(t_argcontent argcontent, long long arg);
/* --------------- parser.c ---------------- */
t_argcontent	ft_parser(char *format, long long i);
t_argcontent	ft_getargcontent(char *spec);
void			ft_initargcontent(t_argcontent *argcontent);
void			ft_initflags(t_argcontent *argcontent, char *spec, int *i);
void			ft_initwpm(t_argcontent *argcontent, char *spec, int *i);
/* --------------- csp.c ---------------- */
int				ft_putc(t_argcontent argcontent, long long arg);
int				ft_putstring(t_argcontent argcontent, char *arg);
int				ft_putp(t_argcontent argcontent, long long arg);
/* --------------- diouxX.c ---------------- */
int				ft_putd(t_argcontent argcontent, long long arg);
void			ft_putminusd_flag(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putzerod_flag(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putwpd_flags(t_argcontent argcontent, long long *i, long long size, long long *arg);
void			ft_putzerod(t_argcontent *argcontent, long long *i, long long *arg);
void			ft_puthashd(t_argcontent argcontent, long long *i, long long *arg);
int				ft_getargsize(t_argcontent argcontent, long long arg);
char			*ft_getoctstr(long long arg, char *modificator);
/* --------------- conversions.c ---------------- */
void			ft_putnbr_big(long long n);
void			ft_putnbr_ubig(unsigned long long n);
char			*ft_gethexstr(long long arg, char c, char *modificator);
char			*ft_getoctstr(long long arg, char *modificator);
long long		ft_atoi_big(const char *str);
long long		ft_atoires_big(const char *str, int i, long long res, int sign);
char			*ft_itoa_big(long long nb);
char			*ft_itoares_big(char *str, long long i, long long n);
long long int	ft_itoa_size(long long nb);
/* --------------- f.c ---------------- */
int				ft_putf(t_argcontent argcontent, float arg);
char			*ft_beforefloat(t_argcontent argcontent, float arg);
char			*ft_ftoa(t_argcontent argcontent, float arg);
char			ft_getfloatchar(float arg, float *h, int leftsize);
int				ft_getfloatsize_r(float arg);
int				ft_getfloatsize_l(float arg);
void 			ft_fastputstr(char *str);

#endif
