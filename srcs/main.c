/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:35:55 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/21 06:31:44 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// чекай мулинет (9), утечки, флоты

int main()
{    
//     unsigned long long c = 9223372036854775808U;
    int *p;

    printf("size: %d\n",         ft_printf("ft_printf output:\n\n%+5o\n\n", 42));
       printf("size: %d\n",         printf("   printf output:\n\n%+5o\n\n", 42));
}
