/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:22:23 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/14 17:28:42 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*map;

	map = *lst;
	while (*lst)
	{
		map = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = map;
	}
	*lst = 0;
}
