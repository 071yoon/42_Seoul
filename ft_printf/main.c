/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:46:45 by 071yoon           #+#    #+#             */
/*   Updated: 2021/12/29 16:49:51 by 071yoon          ###   ########.fr       */
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
	ft_ptf = ft_printf("ft_printf\t %d %u %% %c %s %x %X\n",
			83, -63, c, "string", 123, 456);
	ptf = printf("rl_printf\t %d %u %% %c %s %x %X\n",
			83, -63, c, "string", 123, 456);
	ft_ptf += ft_printf("ft_printf\t %s\n", test);
	ptf += printf("rl_printf\t %s\n", test);
	ft_ptf += ft_printf("ft_printf\t %p\n", d);
	ptf += printf("rl_printf\t %p\n", d);
	printf("ft_ptf : %d\nrl_ptf : %d\n", ft_ptf, ptf);
}
