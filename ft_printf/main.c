/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:46:45 by 071yoon           #+#    #+#             */
/*   Updated: 2022/01/03 18:22:08 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c;
	char	*d;
	int		ft_ptf;
	int		ptf;
	char	*test;

	test = NULL;
	c = 'd';
	d = "test";
	ft_ptf = 0;
	ptf = 0;
	/*
	ft_ptf = ft_printf("ft_printf\t %d %u %% %c %s %x %X\n",
			0, -63, c, "string", 123, 456);
	ptf = printf("rl_printf\t %d %u %% %c %s %x %X\n",
			0, -63, c, "string", 123, 456);

	ft_ptf = ft_printf("%\x7f%d \n", 5);
	ptf = printf("%\x7f%d \n", 5);

	ft_ptf = ft_printf("%c\n", -8);
	ptf = printf("%c\n", -8);
*/
	ft_ptf += ft_printf("ft_printf\t %s\n", test);
	ptf += printf("rl_printf\t %s\n", test);

	ft_ptf += ft_printf("ft_printf\t %p\n", d);	
	ptf += printf("rl_printf\t %p\n", d);
	ft_ptf += ft_printf("ft_printf\t %d%d%d%d\n", 1,2,3,4);	
	ptf += printf("rl_printf\t %d%d%d%d\n", 1,2,3,4);

	printf("ft_ptf : %d\nrl_ptf : %d\n", ft_ptf, ptf);

	ft_printf("dfnlsndl %r dkfnlwefn %d\n",123);
	printf("dfnlsndl %d dkfnlwefn \n",123);

	
}
