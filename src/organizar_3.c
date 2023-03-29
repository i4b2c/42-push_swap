/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizar_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:30:29 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:30:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	organizar_3(t_stack **stack_a)
{
	if ((*stack_a)->valor > (*stack_a)->next->valor
		&& ((valor_do_ultimo(*stack_a) > (*stack_a)->valor
				|| valor_do_ultimo(*stack_a) < (*stack_a)->next->valor)))
		ft_sa(stack_a);
	else if ((valor_do_ultimo(*stack_a) < (*stack_a)->valor)
		|| (valor_do_ultimo(*stack_a) > (*stack_a)->valor
			&& (*stack_a)->next->valor > (*stack_a)->valor))
	{
		if ((*stack_a)->valor < (*stack_a)->next->valor)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
}

void	organizar_stack_3(t_stack **stack_a)
{
	while (1)
	{
		if ((verificar_organizado(*stack_a)) == 0)
			break ;
		organizar_3(stack_a);
	}
}
