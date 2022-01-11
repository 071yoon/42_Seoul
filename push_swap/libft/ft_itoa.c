/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:48:31 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/13 16:01:10 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_cnt(int num)
{
	size_t		cnt;
	long long	n;

	n = num;
	cnt = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	fill_ret(char *ret, int num, size_t len)
{
	long long	n;

	n = num;
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
	}
	if (n >= 10)
	{
		fill_ret(ret, (n / 10), --len);
		ret[len] = (n % 10) + '0';
	}
	else
		ret[--len] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	wd_len;

	wd_len = len_cnt(n);
	ret = malloc(sizeof(char) * (wd_len + 1));
	if (!ret)
		return (NULL);
	fill_ret(ret, n, wd_len);
	ret[wd_len] = '\0';
	return (ret);
}
