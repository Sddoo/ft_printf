/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:44:53 by hfrankly          #+#    #+#             */
/*   Updated: 2019/05/24 19:10:10 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initargcontent(t_argcontent *argcontent)
{
	argcontent->precision = 0;
	argcontent->width = 0;
	argcontent->hash = 0;
	argcontent->minus = 0;
	argcontent->plus = 0;
	argcontent->zero = 0;
	argcontent->point = 0;
}

void	ft_getflags(t_argcontent *argcontent, char *spec, int *i)
{
	while (spec[*i] && (spec[*i] <= '0' || spec[*i] > '9') && spec[*i] != '.')
	{
		if (spec[*i] == '#')
			argcontent->hash = 1;
		else if (spec[*i] == '0')
			argcontent->zero = 1;
		else if (spec[*i] == '-')
			argcontent->minus = 1;
		else if (spec[*i] == '+')
			argcontent->plus = 1;
		(*i)++;
	}
}

void	ft_getwpm(t_argcontent *argcontent, char *spec, int *i)
{
	while (spec[*i] && spec[*i] != '.' && spec[*i] >= '0' && spec[*i] <= '9')
	{
		argcontent->width = argcontent->width * 10 + (spec[*i] - '0');
		(*i)++;
	}
	if (spec[*i] == '.')
	{
		argcontent->point = 1;
		(*i)++;
	}
	while (spec[*i] && spec[*i] >= '0' && spec[*i] <= '9')
	{
		argcontent->precision = argcontent->precision * 10 + (spec[*i] - '0');
		(*i)++;
	}
	if (spec[*i - 2] == 'h' || spec[*i - 2] == 'l')
		argcontent->modificator[0] = spec[*i - 2];
	else
		argcontent->modificator[0] = '\0';
	if (spec[*i - 3] == 'h' || spec[*i - 3] == 'l')
	{
		if (argcontent->modificator[0] != spec[*i - 3])
			exit(0);
		argcontent->modificator[1] = spec[*i - 3];
		argcontent->modificator[2] = '\0';
	}
	else
		argcontent->modificator[1] = '\0';
}

t_argcontent	ft_getargcontent(char *spec) // spec length
{
	t_argcontent	argcontent;
	int		i;

	i = 0;
	argcontent.length = ft_strlen(spec) + 1;
	ft_initargcontent(&argcontent);
	while (spec[i])
	{
		ft_getflags(&argcontent, spec, &i);
		ft_getwpm(&argcontent, spec, &i);
	}
	argcontent.type = spec[i - 1];
	// printf("minus = %d\nplus = %d\nzero = %d\nhash = %d\nwidth = %lld\nprecision = %lld\nmodificator = %s\n", argcontent.minus, argcontent.plus, argcontent.zero, argcontent.hash, argcontent.width, argcontent.precision, argcontent.modificator);
	return (argcontent);
}

t_argcontent	ft_parser(char *format, long long i)
{
	char		*spec;
	long long	begin;
	long long	newi;

	begin = i;
	newi = 0;
	while (format[begin] && format[begin] != 'c' && format[begin] != 's'
	&& format[begin] != 'p' && format[begin] != 'd'
	&& format[begin] != 'i' && format[begin] != 'o'
	&& format[begin] != 'u' && format[begin] != 'x'
	&& format[begin] != 'X' && format[begin] != 'f')
		begin++;
	if (!(spec = (char*)malloc(begin - i + 1)))
		exit(0);
	i++;
	while (format[i] && i <= begin)
		spec[newi++] = format[i++];
	spec[newi] = '\0';
	return (ft_getargcontent(spec));
}
