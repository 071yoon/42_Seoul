/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:04:09 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 17:20:13 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
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
