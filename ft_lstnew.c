/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:44:02 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/14 16:46:29 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*map;

	map = (t_list *)malloc(sizeof(t_list));
	if (!map)
		return (NULL);
	map -> content = content;
	map -> next = NULL;
	return (map);
}
