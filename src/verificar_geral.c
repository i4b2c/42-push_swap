/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_geral.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:46:47 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 19:46:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	verificar_valores_max(t_stack *stack)
{
	int	temp;

	temp = stack->valor;
	while (stack != NULL)
	{
		if (stack->valor > temp)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	verificar_valores_max_prox(t_stack *stack)
{
	int	temp;

	if (!(*stack).next)
		return (0);
	temp = stack->next->valor;
	while (stack != NULL)
	{
		if (stack->valor > temp)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	verificar_valores_max_ultimo(t_stack *stack)
{
	int	temp;

	temp = valor_do_ultimo(stack);
	while (stack != NULL)
	{
		if (stack->valor > temp)
			return (0);
		stack = stack->next;
	}
	return (1);
}
