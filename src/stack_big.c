/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:53:19 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:53:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_geral	*big_check_next(int *i, int *num, t_geral *geral, t_len *len)
{
	if (*i == 0 && geral->next != NULL)
	{
		if (geral->next->next == NULL)
			*i = len->ultimo_elementos;
		else
			*i = len->elementos_stack;
		(*num)++;
		return (geral->next);
	}
	return (geral);
}

int	big_check_end(int i, t_geral *geral, t_stack **stack_a, t_stack **stack_b)
{
	if (i == 0 && geral->next == NULL)
		return (1);
	else if ((*stack_a)->next == NULL)
	{
		ft_pb(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	separar_por_grupo_big(t_len *len, t_stack **stack_a
	, t_stack **stack_b, t_geral *geral)
{
	int	i;
	int	num;
	int	op;

	op = 1;
	i = 0;
	num = len->len_geral / 2;
	while (num-- > 1)
		geral = geral->next;
	num = len->len_geral - (len->len_geral / 2);
	while (geral != NULL)
	{
		geral = big_check_next(&i, &num, geral, len);
		if (big_check_end(i, geral, stack_a, stack_b))
			break ;
		if (verificar_valor_na_stack(geral->stack, (*stack_a)->valor))
			big_pb(&i, stack_a, stack_b);
		else
			big_choose_ra_rra(op, stack_a);
		if (valor_do_ultimo(*stack_a) <= len->media)
			op = 1;
		if ((*stack_a)->valor <= len->media)
			op = 0;
	}
}

void	organizar_big(t_len *len, t_stack **stack_a
	, t_stack **stack_b, t_geral *geral)
{
	int	op;
	int	len_ele;
	int	cont;

	cont = len->ultimo_elementos;
	op = 1;
	len_ele = len->ultimo_elementos;
	while (*stack_b != NULL)
	{
		if (len_ele == 0)
			geral = big_reset(len, &cont, &len_ele, geral);
		if (verificar_valores_max(*stack_b))
			big_pa(&cont, &len_ele, stack_a, stack_b);
		else
			escolher_opcao(&op, &cont, stack_b);
		if (cont >= len_ele)
			op = 1;
		else if (cont <= 0)
			op = 0;
	}
}
