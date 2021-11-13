/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:32:15 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/13 16:50:48 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	i;

	if ((size_t)ft_strlen((char *)s) < start)
		return ("\0");
	pointer = malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		pointer[i++] = s[start++];
	pointer[i] = '\0';
	return (pointer);
}
