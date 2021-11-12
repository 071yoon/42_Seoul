/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:45:36 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/12 18:35:06 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*first_save(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*first;

	first = (char *)s1;
	i = -1;
	while (first[++i] != '\0')
	{
		j = -1;
		while (++j < ft_strlen((char *)set))
		{
			if (first[i] == set[j])
				break ;
		}
		if (first[i] != set[j])
			break ;
	}
	return (&first[i]);
}

static char	*last_save(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*last;

	last = (char *)s1;
	i = ft_strlen((char *)s1);
	while (--i >= 0)
	{
		j = -1;
		while (++j < ft_strlen((char *)set))
		{
			if (last[i] == set[j])
				break ;
		}
		if (last[i] != set[j])
			break ;
	}
	return (&last[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s1;
	char	*first_ptr;
	char	*last_ptr;

	first_ptr = first_save(s1, set);
	last_ptr = last_save(s1, set);
	if (first_ptr >= last_ptr)
		return (ft_strdup(""));
	trimmed_s1 = malloc(sizeof(char) * (last_ptr - first_ptr + 2));
	if (trimmed_s1 == NULL)
		return (NULL);
	ft_strlcpy(trimmed_s1, first_ptr, (last_ptr - first_ptr + 2));
	return (trimmed_s1);
}
