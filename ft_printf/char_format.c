/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:36:26 by 071yoon           #+#    #+#             */
/*   Updated: 2021/12/29 16:45:49 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_form(va_list *ap)
{
	int	arg_char;
	int	ret;

	arg_char = (char)va_arg(*ap, int);
	write(1, &arg_char, 1);
	ret = 1;
	return (ret);
}

int	str_form(va_list *ap)
{
	char	*str;
	int		ret;

	str = (char *)va_arg(*ap, char *);
	ret = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[ret])
	{
		ft_putchar_fd(str[ret], 1);
		ret++;
	}
	return (ret);
}
