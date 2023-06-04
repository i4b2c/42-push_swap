/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:53:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 19:53:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_len(t_len *len, int ac)
{
	int	raiz;

	ft_raiz(&raiz, ac);
	len->raiz = raiz;
	if (ac <= 200)
		len->divisao_stack = ac / raiz;
	else
		len->divisao_stack = (ac / raiz) - 2;
	len->elementos_stack = ac / len->divisao_stack;
	len->ultimo_elementos = (len->elementos_stack + ac
			- (len->elementos_stack * len->divisao_stack));
}

void	get_geral_dividido(t_geral **geral, t_stack *stack, t_len len)
{
	int		count;
	int		i;
	t_geral	*novo;
	t_geral	*atual;
	t_geral	*temp;

	get_geral_iniciar(&count, &novo, &atual);
	while (count < len.divisao_stack)
	{
		criar_temp(&temp);
		get_i(len, &i, count);
		while (i > 0)
		{
			adicionar_fim(&temp->stack, stack->valor);
			stack = stack->next;
			i--;
		}
		if (novo == NULL)
			colocar_inicio(&novo, &atual, temp);
		else
			continua_atual(&atual, temp);
		count++;
	}
	*geral = novo;
}
