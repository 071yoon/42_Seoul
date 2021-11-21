/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:40:45 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/21 17:51:32 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*pointer;

	pointer = (char *)str;
	len = 0;
	while (*pointer != '\0')
	{
		pointer++;
		len++;
	}
	while (len >= 0)
	{
		if (*pointer == c)
			return (pointer);
		else
		{
			pointer--;
			len--;
		}
	}
	return (0);
}
