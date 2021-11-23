/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoyoon <yeoyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:44:02 by yeoyoon           #+#    #+#             */
/*   Updated: 2021/11/21 15:29:30 by yeoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*map;

	map = (t_list *)malloc(sizeof(t_list));
	if (!map)
		return (NULL);
	map->content = content;
	map->next = NULL;
	return (map);
}
