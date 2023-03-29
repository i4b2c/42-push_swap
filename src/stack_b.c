/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:31:02 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:31:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void dividir_stack_b(t_stack **stack_a , t_stack **stack_b,t_geral **geral , t_len len)
{
	t_geral *temp;
	int i;
	int len_d;

	temp = *geral;
	i = 0;
	len_d = 0;
	while(temp != NULL && *stack_a != NULL)
	{
		if(*stack_a)
		{
			if (verificar_valor_na_stack(temp->stack, (*stack_a)->valor) == 1)
			{
				ft_pb(stack_a, stack_b);
				i++;
			}
			else
			{
					ft_ra(stack_a);
			}
		}
		if(i == len.elementos_stack)
		{
			if(len_d + 1 != len.divisao_stack)
			{
				temp = temp->next;
				i = 0;
			}
			len_d++;
		}
	}
	ft_pb(stack_a, stack_b);
}
