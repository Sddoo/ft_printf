/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:08 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/14 19:44:59 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

// #include "../includes/libftprintf.h"
// #include "../libft/libft.h"

int		main()
{
	int *pointer;

	pointer = (int*)malloc(8);
	printf("size: %d\n\n", ft_printf("ft_printf output:\n\n%p\n\n", pointer));
	   printf("size: %d\n",   printf("   printf output:\n\n%p\n\n", pointer));
}
