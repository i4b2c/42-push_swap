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


int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *replica_stack;
	t_geral *geral;
	t_len len;
	len.ac = ac-1;
	stack_a = NULL;
	stack_b = NULL;
	geral = NULL;
	replica_stack = NULL;
	if(verificar_non_numberic(av) == 1
		|| verificar_repitida(av) == 1)
	{
		ft_printf("Error\n");
		return 0;
	}
	else if(len.ac >= 2 )
	{
		dar_valor_a(&stack_a,av);
		get_len(&len,ac-1);
		if(ac == 3 && verificar_organizado(stack_a) == 1)
			simple_sa(&stack_a);
		if(ac >= 10 && verificar_organizado(stack_a) == 1)
		{
			replicar_struct(&replica_stack,stack_a);
			organizar_replica(&replica_stack);
			get_geral_dividido(&geral,replica_stack,len);
			dividir_stack_b(&stack_a,&stack_b,&geral,len);
			start_organizar(&stack_a,&stack_b,len);
		}
		else if(ac > 4 && verificar_organizado(stack_a) == 1)
			organizar_stack_5(&stack_a,&stack_b);
		else if(ac >= 2 && verificar_organizado(stack_a) == 1)
			organizar_stack_3(&stack_a);
		free_todos(&stack_a,&replica_stack,&geral);
	}
}
