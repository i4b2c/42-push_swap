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
