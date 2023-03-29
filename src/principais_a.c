/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principais_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:03:26 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack **stack)
{
	int	temp;

	temp = (*stack)->valor;
	(*stack)->valor = (*stack)->next->valor;
	(*stack)->next->valor = temp;
	ft_printf("sa\n");
}

void	ft_ra(t_stack **stack)
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
	ft_printf("ra\n");
}

void	ft_rra(t_stack **stack)
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
	ft_printf("rra\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	adicionar_inicio(stack_b, (*stack_a)->valor);
	remover_primeiro(stack_a);
	ft_printf("pa\n");
}

void	simple_sa(t_stack **stack)
{
	if ((*stack)->valor > (*stack)->next->valor)
		ft_sa(stack);
}
