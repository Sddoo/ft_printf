/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:35:55 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 05:43:56 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{    
//     unsigned long long c = 9223372036854775808U;
    int *p;

    printf("size: %d\n",         ft_printf("ft_printf output:\n\n%hho\n\n", 255 + 42));
       printf("size: %d\n",         printf("   printf output:\n\n%hho\n\n", 255 + 42));
}
