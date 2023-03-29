/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:14:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:14:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long int	ft_atoll(const char *str)
{
	long long int			result;
	int						sign;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((long long int)result * sign);
}

void	ft_raiz(int *raiz, int ac)
{
	int	i;

	i = 0;
	ac--;
	while (1)
	{
		if (i * i >= ac)
		{
			*raiz = i;
			return ;
		}
		i++;
	}
}
