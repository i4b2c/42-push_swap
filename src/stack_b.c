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

int verificar_melhor_caminho(t_geral *temp, t_stack **stack_a,int op);

void	ft_ra_no_print(t_stack **stack)
{
	t_stack	*new;
	t_stack	*primeiro_no;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = *stack;
	primeiro_no = new;
	while (new->next != NULL)
		new = new->next;
	new->next = primeiro_no;
	*stack = (*stack)->next;
	primeiro_no->next = NULL;
}

void	ft_rra_no_print(t_stack **stack)
{
	t_stack	*new;
	t_stack	*ultimo_no;
	t_stack	*penultimo_no;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = *stack;
	while (new->next != NULL)
	{
		if (new->next != NULL && new->next->next == NULL)
			penultimo_no = new;
		new = new->next;
	}
	ultimo_no = new;
	penultimo_no->next = NULL;
	ultimo_no->next = *stack;
	*stack = ultimo_no;
}

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

int getLenStruct(t_stack **stack)
{
	t_stack *temp;
	int i;

	i = 0;
	temp = *stack;
	while(temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

void replicarStack(t_stack **temp, t_stack **stack)
{
	t_stack *tempStack;

	tempStack = *stack;
	while(tempStack != NULL)
	{
		adicionar_fim(temp,tempStack->valor);
		tempStack = tempStack->next;
	}
}

int verificarMelhorCaminhoRa(t_geral *geral,t_stack **stack)
{
	t_stack *temp;
	int i;
	int len;

	temp = *stack;
	len = getLenStruct(stack);
	i = 0;
	while(i < len)
	{
		if(verificar_valor_na_stack(geral->stack,temp->valor) == 1)
			break;
		temp = temp->next;
		i++;
	}
	return i;

}

int verificarMelhorCaminhoRra(t_geral *geral,t_stack **stack)
{
	t_stack *temp;
	int i;
	int j;
	int len;

	temp = *stack;
	len = getLenStruct(stack);
	i = 0;
	j = 0;
	while(i < len)
	{
		if(verificar_valor_na_stack(geral->stack,temp->valor) == 1)
			j = i;
		temp = temp->next;
		i++;
	}
	return (len-j);

}

void	logica_simples(t_geral *t, t_stack **stack_a, t_stack **stack_b, int *i)
{
	int res;
	int res2;

	res = 0;
	res2 = 0;
	if (verificar_valor_na_stack(t->stack, (*stack_a)->valor) == 1)
	{
		ft_pb(stack_a, stack_b);
		(*i)++;
	}
	else
	{
		res = verificarMelhorCaminhoRa(t,stack_a);
		res2 = verificarMelhorCaminhoRra(t,stack_a);
		if(res <= res2)
		{
			while(res > 0)
			{
				if (verificar_valor_na_stack(t->stack, (*stack_a)->valor) == 1)
				{
					ft_pb(stack_a, stack_b);
					(*i)++;
				}
				res--;
				ft_ra(stack_a);
			}
		}
		else
		{
			while(res2 > 0)
			{
				if (verificar_valor_na_stack(t->stack, (*stack_a)->valor) == 1)
				{
					ft_pb(stack_a, stack_b);
					(*i)++;
				}
				res2--;
		 		ft_rra(stack_a);
			}
		}
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
