/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:22:23 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/21 15:41:23 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*map;

	if (!lst)
		return ;
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
