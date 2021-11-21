/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:45:36 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/21 13:48:15 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], (end - start) + 2);
	return (result);
}
