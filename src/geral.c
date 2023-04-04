/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geral.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:49:02 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 19:49:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	escolher_rotacao(t_stack **stack_b, int *cont, int op)
{
	if (op == 1)
	{
		ft_rrb(stack_b);
		*cont += 1;
	}
	else
	{
		ft_rb(stack_b);
		*cont -= 1;
	}
}

void	geral_loop(t_stack **stack_a, t_stack **stack_b, int *len, int *cont)
{
	int		op;
	t_stack	*temp;

	while ((*len) > 0)
	{
		temp = (*stack_b);
		if ((*cont) == 0)
			op = 1;
		else if ((*cont) >= (*len))
			op = 0;
		if (verificar_valores_max(temp) == 1)
			valores_max(stack_a, stack_b, len, cont);
		else if (verificar_valores_max_prox(temp) == 1)
			valores_max_prox(stack_a, stack_b, len, cont);
		else if ((*stack_b)->next
			&& verificar_valores_max_ultimo(temp) == 1)
			valores_max_ultimo(stack_a, stack_b, len);
		else
			check(stack_b, op, cont);
	}
}

void	start_organizar(t_stack **stack_a, t_stack **stack_b, t_len len_d)
{
	int		len;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	while (i != len_d.divisao_stack)
	{
		if (i == 0)
			len = len_d.ultimo_elementos;
		else
			len = len_d.elementos_stack;
		cont = len;
		geral_loop(stack_a, stack_b, &len, &cont);
		i++;
	}
}
