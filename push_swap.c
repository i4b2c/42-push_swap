#include "push_swap.h"

void adicionar_inicio(t_stack **stack, int valor)
{
	t_stack *novo;
	novo = malloc(sizeof(t_stack));
	novo->valor = valor;
	novo->next = *stack;
	*stack = novo;
}

void adicionar_fim(t_stack **stack, int valor)
{
	t_stack *novo;
	t_stack *temp;
	novo = malloc(sizeof(t_stack));
	temp = malloc(sizeof(t_stack));
	novo->valor = valor;
	novo->next = NULL;
	if(*stack == NULL)
		*stack = novo;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = novo;
	}
}

void adicionar_meio(t_stack **stack, int valor, int ref)
{
	t_stack *novo;
	t_stack *temp;
	novo = malloc(sizeof(t_stack));
	temp = malloc(sizeof(t_stack));
	if(!novo)
		return ;
	temp = *stack;
	novo->valor = valor;
	if(*stack == NULL)
	{
		*stack = novo;
		novo->next = NULL;
	}
	while(temp->valor != ref && temp->next != NULL)
		temp = temp->next;
	novo->next = temp->next;
	temp->next = novo;
}

void printar_struct(t_stack *stack)
{
	if(stack != NULL)
	{
		while(stack->next != NULL)
		{
			printf("%d\n",stack->valor);
			stack = stack->next;
		}
		printf("%d\n",stack->valor);
	}
}

int tamanho_stack(t_stack *stack)
{
	int i;

	i = 0;
	while(stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void remover_lista(t_stack **stack, int num)
{
	t_stack *temp;
	temp = malloc(sizeof(t_stack));
	temp = *stack;
	if(temp->valor == num)
		*stack = temp->next;
	else
	{
		while(temp->next != NULL)
		{
			if(temp->next->valor == num)
				break;
			temp = temp->next;
		}
		temp->next = temp->next->next;
		temp->next->next = NULL;
	}
}

void dar_valor_a(t_stack **stack,char **av)
{
	int i;

	i = 1;
	while(av[i] != NULL)
	{
		adicionar_fim(stack,ft_atoi(av[i]));
		i++;
	}
}

int verificar_organizado(t_stack *stack)
{
	while(stack->next != NULL)
	{
		if(stack->valor >= stack->next->valor)
			return 1;
		stack = stack->next;
	}
	return (0);
}

void ft_sa(t_stack **stack)
{
	if(!((*stack)->next->valor) || !((*stack)->valor))
		return;
	int temp;
	t_stack *new;
	new = malloc(sizeof(t_stack));
	new = *stack;
	temp = new->valor;
	new->valor = new->next->valor;
	new->next->valor = temp;
}

int valor_do_ultimo(t_stack *stack)
{
	while(stack->next != NULL)
		stack = stack->next;
	return(stack->valor);
}

void ft_rra(t_stack **stack)
{
	if(*stack == NULL || (*stack)->next == NULL)
		return;
	t_stack *new;
	t_stack *ultimo_no;
	t_stack *penultimo_no;

	new = malloc(sizeof(t_stack));
	ultimo_no = malloc(sizeof(t_stack));
	penultimo_no = malloc(sizeof(t_stack));
	new = *stack;
	while(new->next != NULL)
	{
		if(new->next != NULL && new->next->next == NULL)
			penultimo_no = new;
		new = new->next;
	}
	ultimo_no = new;
	penultimo_no->next = NULL;
	ultimo_no->next = *stack;
	*stack = ultimo_no;

}

void organizar(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new_a;
	(void)stack_b;
	//t_stack *new_b;
	new_a = malloc(sizeof(t_stack));
	//new_b = malloc(sizeof(t_stack));
	new_a = *stack_a;
	if(new_a->valor > new_a->next->valor)
		ft_sa(stack_a);
	//if((verificar_organizado(*stack_a)) == 1 && new_a->valor < new_a->next->valor)
	else if(valor_do_ultimo(new_a) < new_a->valor)
		ft_rra(stack_a);

}

void organizar_stacks(t_stack **stack_a, t_stack **stack_b)
{
	while(1)
	{
		if((verificar_organizado(*stack_a)) == 0)
			break;
		else
			organizar(stack_a,stack_b);
	}
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if(ac != 1)
	{
		dar_valor_a(&stack_a,av);
		organizar_stacks(&stack_a,&stack_b);
	}
	printar_struct(stack_a);
	printar_struct(stack_b);
}
