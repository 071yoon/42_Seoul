/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 071yoon <071yoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:11:29 by 071yoon           #+#    #+#             */
/*   Updated: 2021/11/10 17:02:59 by 071yoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c != '\0' && (c == '\t' || c == '\f'
			|| c == '\n' || c == '\r' || c == 'v'))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int			i;
	long long	result;
	long long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
