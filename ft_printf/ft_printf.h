/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:53:33 by yeoyoon           #+#    #+#             */
/*   Updated: 2022/01/03 15:12:18 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		deal_format(va_list *ap, char c);
int		int_form(va_list *ap);
int		uns_int_form(va_list *ap);
int		ft_printf(const char *str, ...);
int		char_form(va_list *ap);
int		str_form(va_list *ap);
void	un_putnb(unsigned int n, int fd);
void	ft_un_putnbr_fd(unsigned int n, int fd);
int		small_x_form(va_list *ap);
int		big_x_form(va_list *ap);
int		ft_put_ptr(uintptr_t nbr);
int		ft_puthex_fd(unsigned int nbr, int to_upper, int fd);
int		ptr_form(va_list *ap);
int		other_form(char c);

#endif