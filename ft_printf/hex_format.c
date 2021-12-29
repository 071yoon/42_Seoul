/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:35:59 by 071yoon           #+#    #+#             */
/*   Updated: 2021/12/29 16:43:36 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	small_x_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, int);
	len = ft_puthex_fd((unsigned int)arg_x, 0, 1);
	return (len);
}

int	big_x_form(va_list *ap)
{
	int				len;
	unsigned int	arg_x;

	arg_x = (unsigned int)va_arg(*ap, int);
	len = ft_puthex_fd((unsigned int)arg_x, 1, 1);
	return (len);
}

int	ft_puthex_fd(unsigned int nbr, int to_upper, int fd)
{
	int	ret;

	ret = 0;
	if (nbr >= 16)
		ret += ft_puthex_fd(nbr / 16, to_upper, fd);
	if (to_upper)
	{
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], fd);
		ret++;
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr % 16], fd);
		ret++;
	}
	return (ret);
}
