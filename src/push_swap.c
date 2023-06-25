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

void	printar_struct(t_stack *stack);

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

void	get_media_len(t_len *len, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL
		&& i < (((len->len_geral / 2) * len->elementos_stack)) - 1)
	{
		i++;
		stack = stack->next;
	}
	len->media = stack->valor;
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

void	get_len_geral(t_geral *geral, t_len *len)
{
	int	i;

	i = 0;
	while (geral != NULL)
	{
		geral = geral->next;
		i++;
	}
	len->len_geral = i;
}

int	encontrar_media(t_stack *stack, int media)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->valor == media)
			return (1);
		temp = temp->next;
	}
	return (0);
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

void	big_pb(int *i, t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_a, stack_b);
	(*i)--;
}

void	big_choose_ra_rra(int op, t_stack **stack_a)
{
	if (op == 1)
		ft_ra(stack_a);
	else if (op == 0)
		ft_rra(stack_a);
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

void	big_pa(int *cont, int *len_ele, t_stack **stack_a, t_stack **stack_b)
{
	(*cont)--;
	(*len_ele)--;
	ft_pa(stack_b, stack_a);
}

t_geral	*big_reset(t_len *len, int *cont, int *len_ele, t_geral *geral)
{
	(*len_ele) = len->elementos_stack;
	(*cont) = len->elementos_stack;
	return (geral->next);
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

void	enviar_small(t_len *len, t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->valor <= len->media)
		ft_pb(stack_a, stack_b);
}

void	biggest_stack(t_stack **s_a, t_stack **r, t_geral **g, t_len *l)
{
	t_stack	*stack_b;
	t_geral	*geral;
	t_stack	*replica;

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
	get_len_geral(*g, l);
	get_media_len(l, *r);
	send_media_small(l, s_a, &stack_b);
	separar_por_grupo_small(l, s_a, &stack_b, geral);
	enviar_small(l, s_a, &stack_b);
	separar_por_grupo_big(l, s_a, &stack_b, *g);
	start_organizar(s_a, &stack_b, *l);
	free_todos(&replica, s_a, &geral);
	free_while(r);
	free_geral(g);
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
		if (ac > 10 && verificar_organizado(stack_a) == 1)
			biggest_stack(&stack_a, &replica, &geral, &len);
		else if (ac >= 5 && verificar_organizado(stack_a) == 1)
			organizar_stack_5(&stack_a, &stack_b);
		else if (ac >= 4 && verificar_organizado(stack_a) == 1)
			organizar_stack_3(&stack_a);
		else if (ac == 3 && verificar_organizado(stack_a) == 1)
			simple_sa(&stack_a);
		free_todos(&stack_a, &replica, &geral);
	}
}
