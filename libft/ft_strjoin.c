/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:33:40 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/13 16:14:14 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ret)
		return (NULL);
	ft_strlcat(ret, (char *)s1, len_s1 + 1);
	ft_strlcat(ret, (char *)s2, len_s1 + len_s2 + 1);
	return (ret);
}
