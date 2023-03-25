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

int verificar_valores_max_prox(t_stack *stack)
{
	int temp;
	temp = stack->next->valor;
	while(stack != NULL)
	{
		if(stack->valor > temp)
			return 0;
		stack = stack->next;
	}
	return 1;
}

//int main(int ac ,char **av)
void start_organizar(t_stack **stack_a, t_stack **stack_b, t_len len_d)
{
	t_stack *temp;
	//dar_valor_a(&stack_a,av);
	int i , len, op, cont, len_cont,teste;
	op = 0;
	cont = 0;
	teste = 0;
	while(*stack_b != NULL)
	{

		i = 0;
		if(cont == 0)
			len = len_d.ultimo_elementos;
		else
			len = len_d.elementos_stack;
		len_cont = len;
		(void)len_cont;
		//(void)teste;
		teste = len_cont;
		while(i < len && *stack_b != NULL)
		{
			temp = (*stack_b);
			//teste = len_cont-len;
			if(teste == 1)
				op = 1;
			else if (teste == len)
				op = 0;
			//printf("teste:%d\n",teste);
			if(verificar_valores_max(temp) == 1)
			{
				ft_pa(stack_b,stack_a);//no caso pa
				printf("pa\n");
				i++;
			}
			else if((*stack_b)->next
				&& verificar_valores_max_prox(temp) == 1)
			{
				ft_sa(stack_b);
				printf("sb\n");
				ft_pa(stack_b,stack_a);
				printf("pa\n");
			}
			else
			{
				if(op == 1)
				{
					ft_rra(stack_b);
					printf("rrb\n");
					teste++;
				}
				else
				{
					ft_ra(stack_b);
					printf("rb\n");
					teste--;
				}
			}
			if(i == len)
				i = 0;
		}
		/*printf("stack_b\n");
		printar_struct(stack_b);
		printf("stack_a\n");
		printar_struct(stack_a);*/
	}
}
