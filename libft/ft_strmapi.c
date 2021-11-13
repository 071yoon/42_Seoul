/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:06:31 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/13 16:12:59 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
