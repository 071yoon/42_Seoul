/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:36:51 by 071yoon           #+#    #+#             */
/*   Updated: 2021/12/29 16:54:44 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_form(va_list *ap)
{
	int			len;
	uintptr_t	ptr;

	len = 0;
	ptr = (uintptr_t)va_arg(*ap, void *);
	write(1, "0x", 2);
	len += 2;
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
		len += ft_put_ptr(ptr);
	return (len);
}

int	ft_put_ptr(uintptr_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 16)
	{
		ret += ft_put_ptr (nbr / 16);
		ret += ft_put_ptr (nbr % 16);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
		ret++;
	}
	return (ret);
}
