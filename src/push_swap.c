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

void printar_struct(t_stack *stack);

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
	printar_struct(*s_a);
	printar_struct(stack_b);
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
	write(2, "Error\n", 6);
	exit (0);
}

void get_media_len(t_len *len,t_stack *stack)
{
	int i;

	i = 0;
	while (stack != NULL && i < (((len->len_geral/2)*len->elementos_stack))-1)//certo
	{
		i++;
		stack = stack->next;
	}
	len->media = stack->valor;
}

void send_media_small(t_len *len,t_stack **stack_a,t_stack **stack_b)
{
	t_stack *temp;
	int i = 0;

	temp = *stack_a;
	while(i < (((len->len_geral/2)*len->elementos_stack)))
	{
		if(temp->valor <= len->media)
		{
			ft_pb(&temp,stack_b);
			i++;
		}
		else
			ft_ra(&temp);
	}
}

void get_len_geral(t_geral *geral,t_len *len)
{
	int i = 0;
	while(geral != NULL)
	{
		geral = geral->next;
		i++;
	}
	len->len_geral = i;
}

void printar_geral(t_geral *geral)
{
	int i = 1;
	while(geral != NULL)
	{
		printf("stack = %d\n",i);
		while(geral->stack != NULL)
		{
			printf("valor %d\n",geral->stack->valor);
			geral->stack = geral->stack->next;
		}
		geral = geral->next;
		i++;
		printf("\n");
	}
}

// int verificar_small(int valor,int len,t_geral *geral)
// {
// 	t_geral *temp;

// 	temp = *geral;
// 	while(len > 1)
// 	{
// 		temp = temp->next;
// 		len--;
// 	}
// 	while(temp->stack != NULL)
// 	{
// 		if(verificar_valor_na_stack(temp->stack,valor))
// 			return 1;
// 		temp->stack = temp->stack->next;
// 	}
// 	return 0;
// }

int verificar_smalla(int valor,int len,t_geral *geral)
{
	(void)len;
	if(verificar_valor_na_stack(geral->stack,valor) == 1)
		return 1;
	return 0;
}

void separar_por_grupo_small(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
{
	int i_geral_len;
	int i_geral;

	i_geral = len->len_geral/2;
	i_geral_len = len->elementos_stack;
	while ((*stack_b) != NULL)
	{
		if(i_geral_len == 0)
		{
			i_geral_len = len->elementos_stack;
			geral = geral->next;
			i_geral--;
		}
		if(i_geral == 0)
			break;
		if(verificar_valor_na_stack(geral->stack,(*stack_b)->valor) == 1)
		{
			i_geral_len--;
			ft_pa(stack_b,stack_a);
		}
		else
			ft_rb(stack_b);
	}
}

void printar_struct(t_stack *stack)
{
	printf("stack ->\n");
	while(stack != NULL)
	{
		printf("valor : %d\n",stack->valor);
		stack = stack->next;
	}
	printf("\n");
}

// void separar_por_grupo_small(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
// {
// 	(void)len;
// 	(void)geral;
// 	return ;
// 	while((*stack_b)->next != NULL)
// 	{

// 	}
// 	ft_pa(stack_a,stack_b);
// }

void biggest_stack(t_stack **s_a, t_stack **r, t_geral **g, t_len *l)
{
	t_stack	*stack_b;

	stack_b = NULL;

	replicar_struct(r, *s_a);
	organizar_replica(r);
	get_len(l, l->ac);
	get_geral_dividido(g, *r, *l);
	get_len_geral(*g,l);
	get_media_len(l,*r);
	send_media_small(l,s_a,&stack_b);
	separar_por_grupo_small(l,s_a,&stack_b,*g);
	//printar_geral(*g);
	//printar_struct(*s_a);
	//printar_struct(stack_b);


	// dividir_b(s_a, &stack_b, g, *l);
	// start_organizar(s_a, &stack_b, *l);
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
		if(ac > 10 && verificar_organizado(stack_a) == 1)
			biggest_stack(&stack_a, &replica, &geral, &len);
		//else if ((ac >= 11 && ac <= 150)
		//	&& verificar_organizado(stack_a) == 1)
		//	organizar_10(&stack_a, &replica, &geral, &len);
		else if (ac > 6 && verificar_organizado(stack_a) == 1)
			organizar_stack_5(&stack_a, &stack_b);
		else if (ac >= 4 && verificar_organizado(stack_a) == 1)
			organizar_stack_3(&stack_a);
		else if (ac == 3 && verificar_organizado(stack_a) == 1)
			simple_sa(&stack_a);
		free_todos(&stack_a, &replica, &geral);
	}
}
