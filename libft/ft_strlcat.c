/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:45:50 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 16:54:35 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strlen(dest) > size)
		return (ft_strlen(src) + size);
	len = ft_strlen(dest);
	while (i + ft_strlen(dest) < size - 1 && src[i] != '\0')
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
