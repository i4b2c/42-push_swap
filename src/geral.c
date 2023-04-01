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

void	valores_max(t_stack **stack_a, t_stack **stack_b, int *len, int *teste)
{
	ft_pa(stack_a, stack_b);
	*len -= 1;
	*teste -= 1;
}

void	valores_max_prox(t_stack **s_a, t_stack **s_b, int *len, int *teste)
{
	ft_sb(s_b);
	ft_pa(s_b, s_a);
	*len -= 1;
	*teste -= 1;
}

void	valores_max_ultimo(t_stack **s_a, t_stack **s_b, int *len)
{
	ft_rrb(s_b);
	ft_pa(s_b, s_a);
	*len -= 1;
}

void	escolher_rotacao(t_stack **stack_b, int *teste, int op)
{
	if (op == 1)
	{
		ft_rrb(stack_b);
		*teste += 1;
	}
	else
	{
		ft_rb(stack_b);
		*teste -= 1;
	}
}

void	start_organizar(t_stack **stack_a, t_stack **stack_b, t_len len_d)
{
	t_stack	*temp;
	int		len;
	int		op;
	int		cont;
	int		teste;

	op = 0;
	cont = 0;
	teste = 0;
	while (cont != len_d.divisao_stack)
	{
		if (cont == 0)
			len = len_d.ultimo_elementos;
		else
			len = len_d.elementos_stack;
		teste = len;
		while (len > 0)
		{
			temp = (*stack_b);
			if (teste == 0)
				op = 1;
			else if (teste >= len)
				op = 0;
			if (verificar_valores_max(temp) == 1)
			{
				ft_pa(stack_b, stack_a);
				len--;
				teste--;
			}
			else if (verificar_valores_max_prox(temp) == 1)
			{
				ft_sb(stack_b);
				ft_pa(stack_b, stack_a);
				len--;
				teste--;
			}
			else if ((*stack_b)->next
				&& verificar_valores_max_ultimo(temp) == 1)
			{
				ft_rrb(stack_b);
				ft_pa(stack_b, stack_a);
				len--;
			}
			else
			{
				if (op == 1)
				{
					ft_rrb(stack_b);
					teste++;
				}
				else
				{
					ft_rb(stack_b);
					teste--;
				}
			}
		}
		cont++;
	}
}
