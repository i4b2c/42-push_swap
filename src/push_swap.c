/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:30:54 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	organizar_10(t_stack **s_a, t_stack **r, t_geral **g, t_len *l)
{
	t_stack	*stack_b;

	stack_b = NULL;
	get_len(l, l->ac);
	replicar_struct(r, *s_a);
	organizar_replica(r);
	get_geral_dividido(g, *r, *l);
	dividir_b(s_a, &stack_b, g, *l);
	start_organizar(s_a, &stack_b, *l);
}

void	iniciar_basico(t_stack **s_a, t_stack **s_b, t_geral **g, t_stack **r)
{
	*s_a = NULL;
	*s_b = NULL;
	*g = NULL;
	*r = NULL;
}

void	fechar(void)
{
	write(2,"Error\n",6);
	exit (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*replica;
	t_geral	*geral;
	t_len	len;

	len.ac = ac - 1;
	iniciar_basico(&stack_a, &stack_b, &geral, &replica);
	if (verificar_non_numberic(av) == 1
		|| verificar_repitida(av) == 1)
		fechar();
	else if (len.ac >= 2)
	{
		dar_valor_a(&stack_a, av);
		if (ac == 3 && verificar_organizado(stack_a) == 1)
			simple_sa(&stack_a);
		if (ac >= 10 && verificar_organizado(stack_a) == 1)
			organizar_10(&stack_a, &replica, &geral, &len);
		else if (ac > 4 && verificar_organizado(stack_a) == 1)
			organizar_stack_5(&stack_a, &stack_b);
		else if (ac >= 2 && verificar_organizado(stack_a) == 1)
			organizar_stack_3(&stack_a);
		free_todos(&stack_a, &replica, &geral);
	}
}
