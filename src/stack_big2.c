/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_big2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:54:10 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:54:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_pa(int *cont, int *len_ele, t_stack **stack_a, t_stack **stack_b)
{
	(*cont)--;
	(*len_ele)--;
	ft_pa(stack_b, stack_a);
}

t_geral	*big_reset(t_len *len, int *cont, int *len_ele, t_geral *geral)
{
	(*len_ele) = len->elementos_stack;
	(*cont) = len->elementos_stack;
	return (geral->next);
}

void	big_choose_ra_rra(int op, t_stack **stack_a)
{
	if (op == 1)
		ft_ra(stack_a);
	else if (op == 0)
		ft_rra(stack_a);
}

void	big_pb(int *i, t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_a, stack_b);
	(*i)--;
}
