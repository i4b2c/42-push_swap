/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:00:41 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:29:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/src/libft.h"
#include <limits.h>

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

//verificar.c//
int	verificar_organizado(t_stack *stack);
int	verificar_non_numberic(char **str);
int	verificar_valor_na_stack(t_stack *stack, int valor);
int	verificar_stack_b(t_stack *stack);
int verificar_repitida(char **str);

//geral.c//
void start_organizar(t_stack **stack_a, t_stack **stack_b, t_len len_d);

//get.c//
void get_len(t_len *len,int ac);
void get_geral_dividido(t_geral **geral, t_stack *stack , t_len len);

//replica.c//
void replicar_struct(t_stack **replica,t_stack *stack);
void organizar_replica(t_stack **stack);

//verificar_geral.c//
int	verificar_valores_max(t_stack *stack);
int	verificar_valores_max_prox(t_stack *stack);
int	verificar_valores_max_ultimo(t_stack *stack);

//extra_func.c//
void	adicionar_inicio(t_stack **stack, int valor);
void	adicionar_fim(t_stack **stack, int valor);
void	remover_primeiro(t_stack **stack);
int	valor_do_ultimo(t_stack *stack);

//extra.c//
long long int	ft_atoll(const char *str);
void ft_raiz(int *raiz,int ac);

//iniciar.c//
void dar_valor_a(t_stack **stack, char **av);

//organizar_3.c//
void organizar_3(t_stack **stack_a);
void organizar_stack_3(t_stack **stack_a);

//organizar_5.c//
void organizar(t_stack **stack_a, t_stack **stack_b);
void organizar_stack_5(t_stack **stack_a,t_stack **stack_b);

//principais_a.c//
void ft_pa(t_stack **stack_a,t_stack **stack_b);
void ft_ra(t_stack **stack);
void ft_rra(t_stack **stack);
void ft_sa(t_stack **stack);
void simple_sa(t_stack **stack);

//principais_b.c//
void ft_pb(t_stack **stack_a,t_stack **stack_b);
void ft_rb(t_stack **stack);
void ft_rrb(t_stack **stack);
void ft_sb(t_stack **stack);

//replica.c//
void replicar_struct(t_stack **replica,t_stack *stack);
void organizar_replica(t_stack **stack);

//stack_b.c
void dividir_stack_b(t_stack **stack_a , t_stack **stack_b,t_geral **geral , t_len len);

#endif
