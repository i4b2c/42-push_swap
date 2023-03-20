#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/src/libft.h"

typedef struct d_stack
{
	int valor;
	struct d_stack *next;
}	t_stack;

typedef struct d_arm
{
	int valor;
	struct d_arm *next;
}	t_arm;

typedef struct d_geral
{
	t_arm *arm;
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

#endif
