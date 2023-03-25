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
	if(!(*stack).next)
		return 0;
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

int verificar_valores_max_ultimo(t_stack *stack)
{
	int temp;
	temp = valor_do_ultimo(stack);
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
	int len, op, cont,teste;
	op = 0;
	cont = 0;
	teste = 0;
	while(cont != len_d.divisao_stack)
	{

		if(cont == 0)
			len = len_d.ultimo_elementos;
		else
			len = len_d.elementos_stack;
		//(void)teste;
		teste = len;
		//printf("\n%d\n",len);
		//printar_struct(*stack_b);
		//printf("stack:a\n");
		//printar_struct(*stack_a);
		//sleep(5);
		while(len > 0)
		{
			temp = (*stack_b);
			//teste = len_cont-len;
			if(teste == 0)
				op = 1;
			else if (teste >= len)
				op = 0;
			//printar_struct(*stack_b);
			//printf("\nTeste%d\nLen:%d\n",teste,len);
			//sleep(1);
			//printf("teste:%d\n",teste);
			if(verificar_valores_max(temp) == 1)
			{
				ft_pa(stack_b,stack_a);//no caso pa
				printf("pa\n");
				len--;
				teste--;
				//if(len == 0)
				//	break;
			}
			else if(verificar_valores_max_prox(temp) == 1)
			{
				ft_sa(stack_b);
				printf("sb\n");
				ft_pa(stack_b,stack_a);
				printf("pa\n");
				len--;
				teste--;
				//if(len == 0)
				//	break;
			}
			else if((*stack_b)->next
				&& verificar_valores_max_ultimo(temp) == 1)
			{
				ft_rra(stack_b);
				printf("rrb\n");
				ft_pa(stack_b,stack_a);
				printf("pa\n");
				len--;
				//teste--;
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
		}
		cont++;
		//sleep(100);
		/*printf("stack_b\n");
		printar_struct(stack_b);
		printf("stack_a\n");
		printar_struct(stack_a);*/
	}
	//printf("ok%d\n",teste);
	//printar_struct(*stack_a);
}
