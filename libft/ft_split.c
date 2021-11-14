/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:38:00 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/14 14:58:23 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wd_cnt(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static size_t	let_cnt(char const *s, char c, size_t now)
{
	size_t	cnt;

	cnt = 0;
	while (s[now] == c)
		now++;
	while (s[now] != c && s[now] != '\0')
	{
		now++;
		cnt++;
	}
	return (cnt);
}

static size_t	let_put(char const *s, char c, size_t now, char *ret)
{
	size_t	i;

	i = 0;
	while (s[now] == c)
		now++;
	while (s[now] != c && s[now] != '\0')
	{
		ret[i] = s[now];
		i++;
		now++;
	}
	ret[i] = '\0';
	return (now);
}

char	**ft_split(char const *s, char c)
{
	size_t	wd_num;
	char	**ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	wd_num = wd_cnt(s, c);
	ret = malloc(sizeof(char *) * (wd_cnt(s, c) + 1));
	if (!ret)
		return (NULL);
	while (wd_num-- > 0)
	{
		ret[j] = malloc(sizeof(char) * (let_cnt(s, c, i) + 1));
		if (!ret[j])
			return (NULL);
		i = let_put(s, c, i, ret[j++]);
	}
	ret[wd_cnt(s, c)] = NULL;
	return (ret);
}
