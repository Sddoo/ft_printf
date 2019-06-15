/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:35:55 by hfrankly          #+#    #+#             */
/*   Updated: 2019/06/15 13:58:16 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int main()
{
    printf("size: %d\n", ft_printf("ft_printf output:\n\n%.15f\n\n", 1.156));
    //    printf("size: %d\n", printf("   printf output:\n\n%ld\n\n", (long long)9223372036854775800));
}