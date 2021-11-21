/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:27:44 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/21 17:49:51 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	if (dst <= src)
		while (len--)
			*dest_ptr++ = *src_ptr++;
	else
		while (len--)
			*(dest_ptr + len) = *(src_ptr + len);
	return (dst);
}
