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
	while (stack != NULL && i < (((len->len_geral/2)*len->elementos_stack))-1)
	{
		i++;
		stack = stack->next;
	}
	len->media = stack->valor;
}

void send_media_small(t_len *len,t_stack **stack_a,t_stack **stack_b)
{
	int i = 0;

	while(i < (((len->len_geral/2)*len->elementos_stack)))
	{
		if((*stack_a)->valor <= len->media)
		{
			ft_pb(stack_a,stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
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
	t_geral *temp;

	temp = geral;
	while(temp != NULL)
	{
		printf("stack = %d\n",i);
		while(temp->stack != NULL)
		{
			printf("valor %d\n",temp->stack->valor);
			temp->stack = temp->stack->next;
		}
		temp = temp->next;
		i++;
		printf("\n");
	}
}

int verificar_smalla(int valor,int len,t_geral *geral)
{
	(void)len;
	if(verificar_valor_na_stack(geral->stack,valor) == 1)
		return 1;
	return 0;
}

int encontrar_media(t_stack *stack,int media)
{
	t_stack *temp;

	temp = stack;
	while(temp != NULL)
	{
		if(temp->valor == media)
			return 1;
		temp = temp->next;
	}
	return 0;
}

void separar_por_grupo_small(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
{
	int i_geral_len;
	int i_geral;

	while(encontrar_media(geral->stack,len->media) != 1)
		geral = geral->next;
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

int	verificar_organizado_reverso(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->valor <= stack->next->valor)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	organizar_replica_reverso(t_stack **stack)
{
	t_stack	*temp;
	int		temp_valor;

	temp = NULL;
	while (1)
	{
		temp = *stack;
		if (verificar_organizado_reverso(*stack) == 0)
			break ;
		else
		{
			while (temp->next != NULL)
			{
				if (temp->valor < temp->next->valor)
				{
					temp_valor = temp->valor;
					temp->valor = temp->next->valor;
					temp->next->valor = temp_valor;
				}
				temp = temp->next;
			}
		}
	}
}

void replicar_struct_abaixo_media(t_stack **replica,t_stack *stack)
{
	(void)replica;
	(void)stack;
	printf("ok");
	//printar_struct(stack);
	// while(stack->next != NULL)
	// {

	// 	printf("%d\n",stack->valor);
	// 	//tenho que colocar um if para abaixo da media ...
	// 	adicionar_inicio(replica,stack->valor);
	// 	sleep(10);
	// 	stack = stack->next;
	// }
	// printar_struct(*replica);
	//organizar_replica_reverso(replica);
}

void organizar_small(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
{
	(void)geral;
	t_stack *replica;
	int i = ((len->elementos_stack/2)*len->elementos_stack);
	int op = 0;

	//printar_struct(*stack_a);
	//replicar_struct_abaixo_media(&replica,*stack_a);
	return ;
	while(replica != NULL)
	{
		break;
		if(replica->valor == (*stack_a)->valor)
		{
			remover_primeiro(&replica);
			ft_pb(stack_a,stack_b);
		}
		if(op == 0)
		{
			ft_ra(stack_a);
			i--;
		}
		else if(op == 1)
		{
			ft_rra(stack_a);
			i++;
		}
		if(i == 0)
			op = 1;
		else if(i == ((len->elementos_stack/2)*len->elementos_stack))
			op = 0;
		printf("%d\n",i);
	}
}

void	get_i_reverso(t_len len, int *i, int count)
{
	if (count == 0)
		*i = len.elementos_stack
			+ (len.ac - (len.elementos_stack * len.divisao_stack));
	else
		*i = len.elementos_stack;
}

void	get_geral_dividido_reverso(t_geral **geral, t_stack *stack, t_len len)
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
		get_i_reverso(len, &i, count);
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

void passar_pra_cima(t_len *len,t_stack **stack)
{
	int i;
	static int count;
	static int ini = 0;

	if(ini == 0)
	{
		ini = 1;
		count = len->len_geral/2;
	}
	get_i(*len,&i,count);
	//printf("count : %d e %d e %d\n",count,i,len->len_geral);
	count++;
	while(i > 0)
	{
		ft_rra(stack);
		i--;
	}
}

void send_media_big(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
{
	int i;
	(void)geral;
	(void)stack_b;

	i = len->len_geral/2;
	while(i < len->len_geral)
	{
		passar_pra_cima(len,stack_a);
		i++;
	}
}

void	get_i_r(t_len len, int *i, int count)
{
	if (count == len.divisao_stack)
		*i = len.elementos_stack
			+ (len.ac - (len.elementos_stack * len.divisao_stack));
	else
		*i = len.elementos_stack;
}

void separar_por_grupo_big(t_len *len,t_stack **stack_a,t_stack **stack_b,t_geral *geral)
{
	int len_geral;
	int i;
	int num;
	int i_len;
	int op;
	int teste;

	i_len = 0;
	op = 1;

	num = (len->len_geral/2)-1;
	//if((len->len_geral%2))
	//	num--;
	while(num > 0)
	{
		num--;
		geral = geral->next;
	}
	i = 0;
	num = len->len_geral-(len->len_geral/2);
	//num++;
	//if(num % 2)
		//num--;
	len_geral = (num-1)*len->elementos_stack+len->ultimo_elementos;
	// printf("%d %d\n",len_geral,num);
	// printf("%d %d %d %d %d %d\n",len->divisao_stack,len->elementos_stack,len->len_geral,len->media,len->raiz,len->ultimo_elementos);
	// exit(0);
	(void)op;
	(void)i_len;
	(void)len_geral;

	//
	teste = 0;

	while(geral != NULL)
	{
		if(i == 0 && geral->next != NULL)
		{
			if(geral->next->next == NULL)
				i = len->ultimo_elementos;
			else
				i = len->elementos_stack;
			num++;
			// if(!geral->next)
			// 	break;
			geral = geral->next;
		}
		else if(i == 0 && geral->next == NULL)
			break;
		if(verificar_valor_na_stack(geral->stack,(*stack_a)->valor))
		{
			ft_pb(stack_a,stack_b);
			i--;
		}
		else
		{
			// if(op == 0)
			// {
			// 	i_len++;
			if(op == 1)
				ft_ra(stack_a);
			else if(op == 0)
				ft_rra(stack_a);
			teste++;
			// }
			// else if(op == 1)
			// {
			// 	i_len--;
			// 	ft_rra(stack_a);
			// }
		}
		// if(teste == 20000)
		// 	break;
		// if(teste == 1000)
		// {
		// 	printar_struct(*stack_a);
		// 	printar_struct(*stack_b);
		// 	printar_geral(geral);
		// 	break;
		// }
		// if(i_len >= len_geral)
		// 	op = 1;
		// else if(i_len <= 0)
		// 	op = 0;
		if(valor_do_ultimo(*stack_a) <= len->media)
			op = 1;
		if((*stack_a)->valor <= len->media)
			op = 0;
	}
	// ft_pb(stack_a,stack_b);
	// printar_geral(geral);
	// printar_struct(*stack_a);
	// printar_struct(*stack_b);
	// printf("media %d %d\n",len->media,i);
	// printf("%d %d %d %d\n",num,len->len_geral,len->elementos_stack,len->ultimo_elementos);
	//printf("%d %d %d\n",i,len->elementos_stack,len->ultimo_elementos);
	// while(valor_do_ultimo(*stack_a) > len->media)
	// 	ft_rra(stack_a);
	// while((*stack_a)->valor > len->media)
	// 	ft_pb(stack_a,stack_b);
}

void biggest_stack(t_stack **s_a, t_stack **r, t_geral **g, t_len *l)
{
	t_stack	*stack_b;
	t_geral *geral;
	t_stack *replica;

	replica = calloc(1,sizeof(t_stack));
	geral = malloc(sizeof(t_geral));

	replica = NULL;
	geral = NULL;
	stack_b = NULL;

	replicar_struct(r, *s_a);
	replicar_struct(&replica, *s_a);
	organizar_replica(r);
	organizar_replica_reverso(&replica);
	get_len(l, l->ac);
	get_geral_dividido(g, *r, *l);
	get_geral_dividido_reverso(&geral, replica, *l);
	get_len_geral(*g,l);
	get_media_len(l,*r);
	send_media_small(l,s_a,&stack_b);
	separar_por_grupo_small(l,s_a,&stack_b,geral);
	send_media_big(l,s_a,&stack_b,geral);
	//organizar_small(l,s_a,&stack_b,*g);
	separar_por_grupo_big(l,s_a,&stack_b,*g);
	// printar_struct(stack_b);
	// printar_struct(*s_a);
	//printar_geral(geral);
	// printf("%d\n",l->media);
	//organizar_big()
	//mandar_big()
	//mandar_small()
	// printar_geral(*g);
	// printf("")
	// printf("media %d, len %d,le\n",l->media,l->elementos_stack);
	// printf("stack A -> (acima da media)\n");
	// printar_struct(*s_a);
	// printf("stack B -> (abaixo da media)\n");
	// printar_struct(stack_b);


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
		// else if ((ac >= 11 && ac <= 150)
		// 	&& verificar_organizado(stack_a) == 1)
		// 	organizar_10(&stack_a, &replica, &geral, &len);
		else if (ac > 6 && verificar_organizado(stack_a) == 1)
			organizar_stack_5(&stack_a, &stack_b);
		else if (ac >= 4 && verificar_organizado(stack_a) == 1)
			organizar_stack_3(&stack_a);
		else if (ac == 3 && verificar_organizado(stack_a) == 1)
			simple_sa(&stack_a);
		free_todos(&stack_a, &replica, &geral);
	}
}
