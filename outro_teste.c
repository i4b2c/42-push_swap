#include "push_swap.h"

int verificar_valores_max(t_stack *stack)
{
	int temp;
	temp = stack->valor;
	while(stack != NULL)
	{
		if(stack->valor > temp)
			return 0;
		stack = stack->next;
	}
	return 1;
}

int main(int ac ,char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	stack_a = NULL;
	stack_b = NULL;

	dar_valor_a(&stack_a,av);
	int i , len;
	i = 0;
	len = 5;
	while(stack_a != NULL && i < len)
	{
		if(verificar_valores_max(stack_a) == 1)
		{
			ft_pa(&stack_a,&stack_b);
			printf("pb\n");
			i++;
		}
		else
		{
			ft_ra(&stack_a);
			printf("ra\n");
		}
		if(i == len)
		{
			i = 0;
		}

	}
	printf("stack_b\n");
	printar_struct(stack_b);
	printf("stack_a\n");
	printar_struct(stack_a);
}
