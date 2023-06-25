/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:50:29 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:50:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	enviar_small(t_len *len, t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->valor <= len->media)
		ft_pb(stack_a, stack_b);
}

void	send_media_small(t_len *len, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i < (((len->len_geral / 2) * len->elementos_stack)))
	{
		if ((*stack_a)->valor <= len->media)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
}

void	separar_por_grupo_small(t_len *len, t_stack **stack_a
	, t_stack **stack_b, t_geral *geral)
{
	int	i_geral_len;
	int	i_geral;

	while (encontrar_media(geral->stack, len->media) != 1)
		geral = geral->next;
	i_geral = len->len_geral / 2;
	i_geral_len = len->elementos_stack;
	while ((*stack_b) != NULL)
	{
		if (i_geral_len == 0)
		{
			i_geral_len = len->elementos_stack;
			geral = geral->next;
			i_geral--;
		}
		if (verificar_valor_na_stack(geral->stack, (*stack_b)->valor) == 1)
		{
			i_geral_len--;
			ft_pa(stack_b, stack_a);
		}
		else
			ft_rb(stack_b);
	}
}
