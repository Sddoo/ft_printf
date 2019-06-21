/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:44:53 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 02:34:16 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_initflags(t_argcontent *argcontent, char *spec, int *i)
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
		else if (spec[*i] == ' ')
			argcontent->space = 1;
		(*i)++;
	}
}

void			ft_getmodif(t_argcontent *argcontent, char *spec, int *i)
{
	if (spec[*i - 2] == 'h' || spec[*i - 2] == 'l' || spec[*i - 2] == 'L'
	|| spec[*i - 2] == 'j' || spec[*i - 2] == 'z')
		argcontent->modificator[0] = spec[*i - 2];
	else
		argcontent->modificator[0] = '\0';
	if (spec[*i - 3] == 'h' || spec[*i - 3] == 'l')
	{
		if (argcontent->modificator[0] != spec[*i - 3]
		|| argcontent->modificator[0] == 'j' || argcontent->modificator[0] == 'z')
			exit(0);
		argcontent->modificator[1] = spec[*i - 3];
		argcontent->modificator[2] = '\0';
	}
	else
		argcontent->modificator[1] = '\0';
}

void			ft_initwpm(t_argcontent *argcontent, char *spec, int *i)
{
	while (spec[*i] && spec[*i] != '.' && spec[*i] >= '0'
	&& spec[(*i)] <= '9')
	{
		argcontent->width = argcontent->width * 10 + (spec[*i] - '0');
		(*i)++;
	}
	if (spec[(*i)] == '.')
	{
		argcontent->point = 1;
		(*i)++;
	}
	while (spec[*i] && spec[*i] >= '0' && spec[*i] <= '9')
	{
		argcontent->precision = argcontent->precision * 10 + (spec[*i] - '0');
		(*i)++;
	}
	ft_getmodif(argcontent, spec, i);
}

t_argcontent	ft_getargcontent(char *spec)
{
	t_argcontent	argcontent;
	int				i;

	i = 0;
	argcontent.length = ft_strlen(spec) + 1;
	ft_initargcontent(&argcontent);
	while (spec[i])
	{
		ft_initflags(&argcontent, spec, &i);
		ft_initwpm(&argcontent, spec, &i);
	}
	argcontent.type = spec[i - 1];
	if (argcontent.type == 'O' || argcontent.type == 'D' || argcontent.type == 'U')
	{
		argcontent.modificator[0] = 'l';
		argcontent.modificator[1] = 'l';
		argcontent.modificator[2] = '\0';
	}
	if (argcontent.type == 'O')
		argcontent.type = 'o';
	else if (argcontent.type == 'D')
		argcontent.type = 'd';
	else if (argcontent.type == 'U')
		argcontent.type = 'u';
	return (argcontent);
}

t_argcontent	ft_parser(char *format, long long i)
{
	char		*spec;
	long long	begin;
	long long	newi;

	begin = ++i;
	newi = 0;
	while (format[begin] && format[begin] != 'c' && format[begin] != 's'
	&& format[begin] != 'p' && format[begin] != 'd'
	&& format[begin] != 'i' && format[begin] != 'o'
	&& format[begin] != 'u' && format[begin] != 'x'
	&& format[begin] != 'X' && format[begin] != 'f'
	&& format[begin] != 'O' && format[begin] != 'D'
	&& format[begin] != 'U' && format[begin] != '%')
		begin++;
	if (!(spec = (char*)malloc(begin - i + 1)))
		exit(0);
	while (format[i] && i <= begin)
		spec[newi++] = format[i++];
	spec[newi] = '\0';
	return (ft_getargcontent(spec));
}
