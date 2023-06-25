/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:00:41 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 16:29:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct d_stack
{
	int				valor;
	struct d_stack	*next;
}	t_stack;

typedef struct d_geral
{
	struct d_stack	*stack;
	struct d_geral	*next;
}	t_geral;

typedef struct d_len
{
	int	raiz;
	int	ac;
	int	divisao_stack;
	int	ultimo_elementos;
	int	elementos_stack;
	int	media;
	int	len_geral;
}	t_len;

//verificar.c//
int					verificar_organizado(t_stack *stack);
int					verificar_non_numberic(char **str);
int					verificar_valor_na_stack(t_stack *stack, int valor);
int					verificar_stack_b(t_stack *stack);
int					verificar_repitida(char **str);

//verificar_geral.c//
int					verificar_valores_max(t_stack *stack);
int					verificar_valores_max_prox(t_stack *stack);
int					verificar_valores_max_ultimo(t_stack *stack);

//stack_small.c//
void				enviar_small(t_len *len, t_stack **stack_a,
						t_stack **stack_b);
void				send_media_small(t_len *len, t_stack **stack_a,
						t_stack **stack_b);
void				separar_por_grupo_small(t_len *len, t_stack **stack_a,
						t_stack **stack_b, t_geral *geral);

//stack_big2.c//
void				big_pa(int *cont, int *len_ele,
						t_stack **stack_a, t_stack **stack_b);
t_geral				*big_reset(t_len *len, int *cont,
						int *len_ele, t_geral *geral);
void				big_choose_ra_rra(int op, t_stack **stack_a);
void				big_pb(int *i, t_stack **stack_a, t_stack **stack_b);

//stack_big.c//
t_geral				*big_check_next(int *i, int *num,
						t_geral *geral, t_len *len);
int					big_check_end(int i, t_geral *geral,
						t_stack **stack_a, t_stack **stack_b);
void				separar_por_grupo_big(t_len *len, t_stack **stack_a,
						t_stack **stack_b, t_geral *geral);
void				organizar_big(t_len *len, t_stack **stack_a,
						t_stack **stack_b, t_geral *geral);

//stack_b.c//
int					verificar_ra(t_geral *temp, t_stack **stack_a);
int					verificar_rra(t_geral *temp, t_stack **stack_a);
int					get_len_struct(t_stack **stack);
int					verificar_melhor_caminho_ra(t_geral *geral,
						t_stack **stack);
int					verificar_melhor_caminho_rra(t_geral *geral,
						t_stack **stack);

//replica.c//
void				replicar_struct(t_stack **replica, t_stack *stack);
void				organizar_replica(t_stack **stack);
int					verificar_organizado_reverso(t_stack *stack);
void				organizar_replica_reverso(t_stack **stack);
void				replicar_stack(t_stack **temp, t_stack **stack);

//push_swap.c//
void				iniciar_basico(t_stack **stack_a, t_stack **stack_b,
						t_geral **geral, t_stack **replica);
void				fechar(void);
void				get_i_reverso(t_len len, int *i, int count);
void				biggest_stack(t_stack **stack_a, t_stack **replica,
						t_geral **geral, t_len *len);

//principais_b.c//
void				ft_sb(t_stack **stack);
void				ft_rb(t_stack **stack);
void				ft_rrb(t_stack **stack);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

//principais_a.c//
void				ft_sa(t_stack **stack);
void				ft_ra(t_stack **stack);
void				ft_rra(t_stack **stack);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				simple_sa(t_stack **stack);

//organizar_5.c//
void				escolher_logica_5(t_stack **stack_a, t_stack **stack_b);
void				organizar(t_stack **stack_a, t_stack **stack_b);
void				organizar_stack_5(t_stack **stack_a, t_stack **stack_b);

//organizar_3.c//
void				organizar_3(t_stack **stack_a);
void				organizar_stack_3(t_stack **stack_a);

//option.c//
void				escolher_opcao(int *op, int *cont,
						t_stack **stack_b);

//no_print.c//
void				ft_ra_no_print(t_stack **stack);
void				ft_rra_no_print(t_stack **stack);

//media.c//
void				get_media_len(t_len *len, t_stack *stack);
int					encontrar_media(t_stack *stack, int media);

//iniciar.c//
void				dar_valor_a(t_stack **stack, char **av);

//get.c//
void				get_len(t_len *len, int ac);
void				free_temp_geral(t_geral *geral);
void				get_geral_dividido(t_geral **g, t_stack *s, t_len l);
void				get_len_geral(t_geral *geral, t_len *len);
void				get_geral_dividido_reverso(t_geral **geral,
						t_stack *stack, t_len len);

//get_extra.c//
void				continua_atual(t_geral **atual, t_geral *temp);
void				colocar_inicio(t_geral **n, t_geral **a, t_geral *t);
void				get_i(t_len len, int *i, int count);
void				get_geral_iniciar(int *c, t_geral **n, t_geral **a);
void				criar_temp(t_geral **temp);

//geral.c//
void				escolher_rotacao(t_stack **s_a, int *cont, int op);
void				geral_loop(t_stack **s_a, t_stack **s_b, int *l, int *c);
void				start_organizar(t_stack **s_a, t_stack **s_b, t_len l);

//geral_extra.c//
void				check(t_stack **s_a, int op, int *cont);
void				valores_max(t_stack **s_a, t_stack **s_b, int *l, int *c);
void				valores_max_prox(t_stack **a, t_stack **b, int *l, int *c);
void				valores_max_ultimo(t_stack **s_a, t_stack **s_b, int *len);

//stack_b.c
void				dividir_b(t_stack **a, t_stack **s, t_geral **g, t_len l);

//extra.c//
long long int		ft_atoll(const char *str);
void				ft_raiz(int *raiz, int ac);

//extra_func.c//
void				adicionar_inicio(t_stack **stack, int valor);
void				adicionar_fim(t_stack **stack, int valor);
void				remover_primeiro(t_stack **stack);
int					valor_do_ultimo(t_stack *stack);

//erro.c//
void				free_todos(t_stack **s_a, t_stack **r, t_geral **g);
void				free_while(t_stack **stack);
void				free_geral(t_geral **geral);

#endif
