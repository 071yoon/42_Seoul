/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:39:44 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/12/29 16:43:51 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	va_start(ap, str);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret += write(1, &str[i++], 1);
		else
		{
			i++;
			ret += deal_format(&ap, str[i++]);
		}
	}
	va_end(ap);
	return (ret);
}

int	deal_format(va_list *ap, char c)
{
	int	ret;

	if (c == 'd' || c == 'i')
		ret = int_form(ap);
	else if (c == 'u')
		ret = uns_int_form(ap);
	else if (c == 'x')
		ret = small_x_form(ap);
	else if (c == 'X')
		ret = big_x_form(ap);
	else if (c == 'c')
		ret = char_form(ap);
	else if (c == 's')
		ret = str_form(ap);
	else if (c == 'p')
		ret = ptr_form(ap);
	else if (c == '%')
	{
		write(1, "%", 1);
		ret = 1;
	}
	else
		return (0);
	return (ret);
}
