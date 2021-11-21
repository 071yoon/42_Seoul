/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:45:50 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/21 13:49:15 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (dest_len > size)
		return (ft_strlen(src) + size);
	len = ft_strlen(dest);
	while (len < size - 1 && src[i] != '\0')
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest_len + ft_strlen(src));
}
