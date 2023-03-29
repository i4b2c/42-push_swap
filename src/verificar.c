/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:25:24 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 18:25:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	verificar_organizado(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->valor >= stack->next->valor)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	verificar_non_numberic(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] != '-'
				&& !(str[i][0] <= '9' && str[i][0] >= '0'))
				return (1);
			else if (j != 0 && !(str[i][j] <= '9' && str[i][j] >= '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verificar_valor_na_stack(t_stack *stack, int valor)
{
	while (stack != NULL)
	{
		if (stack->valor == valor)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	verificar_stack_b(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	return (1);
}

int	verificar_repitida(char **str)
{
	long long int	temp;
	int				i;
	int				j;

	i = 1;
	while (str[i] != NULL)
	{
		j = 1;
		temp = ft_atoll(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (1);
		while (str[j] != NULL)
		{
			if (i != j && temp == ft_atoll(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
