/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:00:41 by marvin            #+#    #+#             */
/*   Updated: 2023/03/25 19:44:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/src/libft.h"

typedef struct d_stack
{
	int valor;
	struct d_stack *next;
}	t_stack;

typedef struct d_geral
{
	struct d_stack *stack;
	struct d_geral *next;
}	t_geral;

typedef struct d_len
{
	int len_a;
	int len_b;
	int raiz;
	int ac;
	int divisao_stack;
	int ultimo_elementos;
	int elementos_stack;
}	t_len;

//principais
void ft_pa(t_stack **stack_a,t_stack **stack_b);
void ft_ra(t_stack **stack);
void ft_rra(t_stack **stack);

void dar_valor_a(t_stack **stack , char **av);
void printar_struct(t_stack *stack);
void adicionar_inicio(t_stack **stack, int valor);
void adicionar_fim(t_stack **stack, int valor);
void get_stack(t_len *len,int ac);
void ft_raiz(int *raiz,int ac);
void get_stack(t_len *len,int ac);
int verificar_organizado(t_stack *stack);
//teste
int verificar_repitida(char **str);
void organizar_replica(t_stack **stack);
void get_len(t_len *len,int ac);
void get_geral_dividido(t_geral **geral, t_stack *stack , t_len len);
void replicar_struct(t_stack **replica,t_stack *stack);
void printar_geral(t_geral **geral);

//outro teste
void start_organizar(t_stack **stack_a, t_stack **stack_b);
int verificar_valores_max(t_stack *stack);

#endif
