/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:04:09 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/11 20:55:00 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	int				i;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (n--)
	{
		if (*ptr_s == (unsigned char)c)
			return (ptr_s);
		else
			ptr_s++;
	}
	return (0);
}
