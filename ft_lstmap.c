/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:34:51 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/17 13:47:08 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*map;

	if (lst == 0 || f == 0)
		return (NULL);
	result = ft_lstnew((*f)(lst -> content));
	if (!result)
		return (NULL);
	map = result;
	lst = lst->next;
	while (lst)
	{
		map -> next = ft_lstnew((*f)(lst -> content));
		if (!(map -> next))
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		map = map->next;
		lst = lst->next;
	}
	return (result);
}
