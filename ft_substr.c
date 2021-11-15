/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:32:15 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/13 17:58:00 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_cpy;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	s_cpy = malloc(len + 1);
	if (!s_cpy)
		return (NULL);
	while (s[++i] != '\0')
		if (i >= start && j < len)
			s_cpy[j++] = s[i];
	s_cpy[j] = '\0';
	return (s_cpy);
}
