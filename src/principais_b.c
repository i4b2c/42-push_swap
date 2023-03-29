/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principais_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:04:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:04:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sb(t_stack **stack)
{
	int	temp;

	temp = (*stack)->valor;
	(*stack)->valor = (*stack)->next->valor;
	(*stack)->next->valor = temp;
	ft_printf("sb\n");
}

void	ft_rb(t_stack **stack)
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
	ft_printf("rb\n");
}

void	ft_rrb(t_stack **stack)
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
	ft_printf("rrb\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	adicionar_inicio(stack_b, (*stack_a)->valor);
	remover_primeiro(stack_a);
	ft_printf("pb\n");
}
