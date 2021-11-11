/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:36:56 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/11 21:36:18 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*ret;
	int		i;

	len_s1 = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len_s1 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
