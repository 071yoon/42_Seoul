/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:36:56 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/12 16:01:40 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*ret;
	int		i;

	len_s1 = 0;
	i = 0;
	while (s1[i++] != '\0')
		len_s1++;
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
