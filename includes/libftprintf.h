/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:04:12 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 03:27:43 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_argcontent	t_argcontent;

struct			s_argcontent
{
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			point;
	int			space;
	long long	width;
	long long	precision;
	char		modificator[3];
	char		type;
	long long	length;
};

int				ft_printf(char *format, ...);
int				ft_putarg(t_argcontent argcontent, va_list ap);
int				ft_putlong(t_argcontent argcontent, long long arg);
t_argcontent	ft_parser(char *format, long long i);
t_argcontent	ft_getargcontent(char *spec);
void			ft_initargcontent(t_argcontent *argcontent);
void			ft_initflags(t_argcontent *argcontent, char *spec, int *i);
void			ft_initwpm(t_argcontent *argcontent, char *spec, int *i);
void			ft_getmodif(t_argcontent *argcontent, char *spec, int *i);
int				ft_putc(t_argcontent argcontent, long long arg);
int				ft_putstring(t_argcontent argcontent, char *arg);
int				ft_putp(t_argcontent argcontent, long long arg);
int				ft_putd(t_argcontent argcontent, long long arg);
void			ft_putplus(t_argcontent *argcontent, long long *arg);
void			ft_putminusd_flag(t_argcontent argcontent, long long *i,
long long size, long long *arg);
void			ft_putzerod_flag(t_argcontent argcontent, long long *i,
long long size, long long *arg);
void			ft_putwpd_flags(t_argcontent argcontent, long long *i,
long long size, long long *arg);
void			ft_putzerod(t_argcontent *argcontent, long long *i,
long long *arg);
void			ft_puthashd(t_argcontent argcontent, long long *i,
long long *arg);
int				ft_getargsize(t_argcontent argcontent, long long arg);
char			*ft_getoctstr(long long arg, char *modificator);
int				ft_getuargsize(t_argcontent argcontent, unsigned long long arg);
void			ft_inithex(t_argcontent *argcontent, char **hex, long long arg);
void			ft_inittype(t_argcontent argcontent, unsigned long long *uarg,
long long *arg);
int				ft_initsize(t_argcontent argcontent, long long *arg,
unsigned long long *uarg, char *hex);
void			ft_putflags(t_argcontent argcontent, long long *i, int size,
long long *arg);
void			ft_putnbr_big(long long n);
void			ft_putnbr_ubig(unsigned long long n);
char			*ft_gethexstr(long long arg, char c, char *modificator);
char			*ft_getoctstr(long long arg, char *modificator);
long long		ft_atoi_big(const char *str);
long long		ft_atoires_big(const char *str, int i, long long res, int sign);
char			*ft_itoa_big(long long nb);
char			*ft_itoares_big(char *str, long long i, long long n);
long long int	ft_itoa_size(long long nb);
void			ft_inituarg(long long arg, unsigned long long *uarg,
char *modificator);
int				ft_getusize(unsigned long long uarg, int b);
int				ft_getsize(long long arg, int b);
int				ft_putf(t_argcontent argcontent, double arg);
int				ft_putlf(t_argcontent argcontent, long double arg);
char			*ft_beforefloat(t_argcontent argcontent, long double arg);
char			*ft_ftoa(t_argcontent argcontent, long double arg);
char			ft_getfloatchar(long double arg, long double *h, int leftsize);
int				ft_getfloatsize_r(long double arg);
int				ft_getfloatsize_l(long double arg);
char			*ft_getfloatpart_r(t_argcontent argcontent, long double arg);
void			ft_fastputstr(char *str);
char			ft_getfloatchar_r(long double *arg);

#endif
