/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:27:44 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 15:57:13 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (ptr_dest < ptr_src)
	{
		while (len--)
			*ptr_dest++ = *ptr_src++;
	}
	else
	{
		while (len--)
			*(ptr_dest + len) = *(ptr_src + len);
	}
	return (dest);
}
