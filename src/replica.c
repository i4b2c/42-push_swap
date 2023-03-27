/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replica.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:50:17 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 19:50:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void replicar_struct(t_stack **replica,t_stack *stack)
{
	if(stack != NULL)
	{
		while(stack->next != NULL)
		{
			adicionar_fim(replica,stack->valor);
			stack = stack->next;
		}
		adicionar_fim(replica,stack->valor);
	}
}

void organizar_replica(t_stack **stack)
{
	t_stack *temp;
	int temp_valor;

	temp = NULL;
	while(1)
	{
		temp = *stack;
		if(verificar_organizado(*stack)==0)
			break;
		else
		{
			while(temp->next != NULL)
			{
				if(temp->valor > temp->next->valor)
				{
					temp_valor = temp->valor;
					temp->valor = temp->next->valor;
					temp->next->valor = temp_valor;
				}
				temp = temp->next;
			}
		}
	}
}
