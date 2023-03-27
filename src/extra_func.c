/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:21:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 18:21:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	adicionar_inicio(t_stack **stack, int valor)
{
	t_stack	*novo;

	novo = malloc(sizeof(t_stack));
	novo->valor = valor;
	novo->next = *stack;
	*stack = novo;
}

void	adicionar_fim(t_stack **stack, int valor)
{
	t_stack *novo;
	t_stack *temp;

	novo = malloc(sizeof(t_stack));
	temp = malloc(sizeof(t_stack));
	novo->valor = valor;
	novo->next = NULL;
	if (*stack == NULL)
		*stack = novo;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = novo;
	}
}

void	remover_primeiro(t_stack **stack)
{
	if (*stack != NULL)
	{
		t_stack *new = *stack;
		*stack = (*stack)->next;
		free (new);
	}
}

int	valor_do_ultimo(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->valor);
}
