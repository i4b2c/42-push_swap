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

//int main(int ac ,char **av)
void start_organizar(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	//dar_valor_a(&stack_a,av);
	int i , len;
	i = 0;
	len = 5;
	while(*stack_b != NULL && i < len)
	{
		temp = (*stack_b);
		if(verificar_valores_max(temp) == 1)
		{
			ft_pa(stack_b,stack_a);//no caso pa
			printf("pa\n");
			i++;
		}
		else
		{
			ft_rra(stack_b);
			printf("rrb\n");
		}
		if(i == len)
		{
			i = 0;
		}

	}
	/*printf("stack_b\n");
	printar_struct(stack_b);
	printf("stack_a\n");
	printar_struct(stack_a);*/
}
