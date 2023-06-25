/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:55:34 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	escolher_opcao(int *op, int *cont, t_stack **stack_b)
{
	if (*op == 1)
	{
		(*cont)--;
		ft_rb(stack_b);
	}
	else if (*op == 0)
	{
		(*cont)++;
		ft_rrb(stack_b);
	}
}
