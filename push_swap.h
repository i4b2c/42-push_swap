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
	t_stack *stack;
	struct d_geral *next;
}	t_geral;

typedef struct d_len
{
	int len_a;
	int len_b;
	int raiz;
	int ac;
	int divisao_stack;
	int elementos_stack;
}	t_len;

void dar_valor_a(t_stack **stack , char **av);
void printar_struct(t_stack *stack);
void adicionar_inicio(t_stack **stack, int valor);
void adicionar_fim(t_stack **stack, int valor);
void get_stack(t_len *len,int ac);
void ft_raiz(int *raiz,int ac);
void get_stack(t_len *len,int ac);
int verificar_organizado(t_stack *stack);

#endif
