/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:40:45 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/21 17:51:32 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;
	int			i;

	i = 0;
	last = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last = &str[i];
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return ((char *)last);
}
