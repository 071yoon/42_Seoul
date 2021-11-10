/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:31:49 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 11:39:47 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalnum(char c);
int		ft_isalpha(char c);
int		ft_isascii(char c);
int		ft_isdigit(int c);
int		ft_isprint(char c);
size_t	strlcpy(char *dest, char *src, size_t destsize);
size_t	ft_strlen(char *str);
int		ft_tolower(char c);
int		to_upper(char c);

#endif