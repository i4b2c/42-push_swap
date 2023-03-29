/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizar_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:30:40 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	organizar(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->valor > (*stack_a)->next->valor
		&& ((valor_do_ultimo(*stack_a) > (*stack_a)->valor
				|| valor_do_ultimo(*stack_a) < (*stack_a)->next->valor)))
		ft_sa(stack_a);
	else if ((valor_do_ultimo(*stack_a) < (*stack_a)->valor))
	{
		if ((*stack_a)->valor < (*stack_a)->next->valor)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
	else if (!((*stack_a)->valor > (*stack_a)->next->valor)
		&& !((valor_do_ultimo(*stack_a) < (*stack_a)->valor))
		&& verificar_organizado(*stack_a) == 1)
		ft_pb(stack_a, stack_b);
	if (*stack_b)
	{
		if ((*stack_b)->next && (*stack_b)->valor < (*stack_b)->next->valor)
			ft_sb(stack_b);
		else if ((*stack_b)->next
			&& valor_do_ultimo(*stack_b) > (*stack_b)->valor)
		{
			if ((*stack_b)->valor > (*stack_b)->next->valor)
				ft_rrb(stack_b);
			else
				ft_rb(stack_b);
		}
		else if (verificar_organizado(*stack_a) == 0)
			ft_pa(stack_b, stack_a);
	}
}

void	organizar_stack_5(t_stack **stack_a, t_stack **stack_b)
{
	while (1)
	{
		if ((verificar_organizado(*stack_a)) == 0
			&& *stack_b == NULL)
			break ;
		organizar(stack_a, stack_b);
	}
}
