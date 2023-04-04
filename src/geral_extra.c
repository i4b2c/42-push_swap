/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geral_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:16:15 by marvin            #+#    #+#             */
/*   Updated: 2023/04/04 10:16:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check(t_stack **stack_b, int op, int *cont)
{
	if (op == 1)
	{
		ft_rrb(stack_b);
		(*cont)++;
	}
	else
	{
		ft_rb(stack_b);
		(*cont)--;
	}
}

void	valores_max(t_stack **stack_a, t_stack **stack_b, int *len, int *cont)
{
	ft_pa(stack_b, stack_a);
	(*len)--;
	(*cont)--;
}

void	valores_max_prox(t_stack **s_a, t_stack **s_b, int *len, int *cont)
{
	ft_sb(s_b);
	ft_pa(s_b, s_a);
	(*len)--;
	(*cont)--;
}

void	valores_max_ultimo(t_stack **stack_a, t_stack **stack_b, int *len)
{
	ft_rrb(stack_b);
	ft_pa(stack_b, stack_a);
	(*len)--;
}
