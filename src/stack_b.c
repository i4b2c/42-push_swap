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

int	verificar_melhor_caminho(t_geral *temp, t_stack **stack_a, int op);

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

int	verificar_ra(t_geral *temp, t_stack **stack_a)
{
	int		res;
	t_geral	temp_geral;
	t_stack	*temp_stack;

	temp_stack = *stack_a;
	temp_geral = *temp;
	res = 0;
	while (verificar_valor_na_stack((&temp_geral)->stack
			, temp_stack->valor) != 1)
	{
		ft_ra(&temp_stack);
		res++;
	}
	return (res);
}

int	verificar_rra(t_geral *temp, t_stack **stack_a)
{
	int		res;
	t_geral	temp_geral;
	t_stack	*temp_stack;

	temp_stack = *stack_a;
	temp_geral = *temp;
	res = 0;
	while (verificar_valor_na_stack((&temp_geral)->stack
			, temp_stack->valor) != 1)
	{
		ft_rra(&temp_stack);
		res++;
	}
	return (res);
}

int	get_len_struct(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	replicar_stack(t_stack **temp, t_stack **stack)
{
	t_stack	*temp_stack;

	temp_stack = *stack;
	while (temp_stack != NULL)
	{
		adicionar_fim(temp, temp_stack->valor);
		temp_stack = temp_stack->next;
	}
}

int	verificar_melhor_caminho_ra(t_geral *geral, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		len;

	temp = *stack;
	len = get_len_struct(stack);
	i = 0;
	while (i < len)
	{
		if (verificar_valor_na_stack(geral->stack, temp->valor) == 1)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	verificar_melhor_caminho_rra(t_geral *geral, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		len;

	temp = *stack;
	len = get_len_struct(stack);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (verificar_valor_na_stack(geral->stack, temp->valor) == 1)
			j = i;
		temp = temp->next;
		i++;
	}
	return (len - j);
}
