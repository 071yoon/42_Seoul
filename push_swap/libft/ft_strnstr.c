/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:47:58 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/12 16:14:15 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack_cpy;

	i = 0;
	haystack_cpy = (char *)haystack;
	if (needle[i] == '\0')
		return (haystack_cpy);
	while (i < len && haystack_cpy[i] != '\0')
	{
		j = 0;
		if (haystack_cpy[i] == needle[j])
		{
			while ((haystack_cpy[i + j] == needle[j])
				&& (needle[j] != '\0') && (i + j < len))
				j++;
			if (needle[j] == '\0')
				return (&haystack_cpy[i]);
		}
		i++;
	}
	return (0);
}
