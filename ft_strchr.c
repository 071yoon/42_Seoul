/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:22:00 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/12 15:51:54 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*pointer;

	pointer = (char *)str;
	while (*pointer)
	{
		if (*pointer == c)
			return (pointer);
		else
			pointer++;
	}
	if (*pointer == c)
		return (pointer);
	return (0);
}
