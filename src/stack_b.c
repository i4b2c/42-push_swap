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

int verificar_ra(t_geral *temp, t_stack **stack_a)
{
	int res;
	t_geral tempGeral;
	t_stack *tempStack;

	tempStack = *stack_a;
	tempGeral = *temp;
	res = 0;
	while(verificar_valor_na_stack((&tempGeral)->stack,tempStack->valor) != 1)
	{
		ft_ra(&tempStack);
		res++;
	}
	return res;
}

int verificar_rra(t_geral *temp, t_stack **stack_a)
{
	int res;
	t_geral tempGeral;
	t_stack *tempStack;

	tempStack = *stack_a;
	tempGeral = *temp;
	res = 0;
	while(verificar_valor_na_stack((&tempGeral)->stack,tempStack->valor) != 1)
	{
		ft_rra(&tempStack);
		res++;
	}
	return res;
}

int verificar_melhor_caminho(t_geral *temp, t_stack **stack_a)
{
	int res_ra;
	int res_rra;

	res_ra = verificar_ra(temp, stack_a);
	res_rra = verificar_rra(temp, stack_a);
	return (res_ra-res_rra);
}

void	logica_simples(t_geral *t, t_stack **stack_a, t_stack **stack_b, int *i)
{
	if (verificar_valor_na_stack(t->stack, (*stack_a)->valor) == 1)
	{
		ft_pb(stack_a, stack_b);
		(*i)++;
	}
	else//aqui onde tenho que verificar qual o melhor
	{
		//esta area esta com infinite loop , nao sei porque ainda
		//if(verificar_melhor_caminho(t,stack_a) < 0)
		//	ft_ra(stack_a);
		//else
			ft_rra(stack_a);
	}
}

void	dividir_b(t_stack **stack_a, t_stack **stack_b, t_geral **g, t_len len)
{
	t_geral	*temp;
	int		i;
	int		len_d;

	temp = *g;
	i = 0;
	len_d = 0;
	while (temp != NULL && *stack_a != NULL)
	{
		if (*stack_a)
			logica_simples(temp, stack_a, stack_b, &i);
		if (i == len.elementos_stack)
		{
			if (len_d + 1 != len.divisao_stack)
			{
				temp = temp->next;
				i = 0;
			}
			len_d++;
		}
	}
	ft_pb(stack_a, stack_b);
}
