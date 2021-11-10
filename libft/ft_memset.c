/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:20:27 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 14:50:03 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*pointer;

	pointer = (unsigned char *) b;
	i = 0;
	while (len >= 0)
	{
		pointer[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
