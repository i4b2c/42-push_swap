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

void remover_primeiro(t_stack **stack)
{
	if(*stack != NULL)
	{
		t_stack *new = *stack;
		*stack = (*stack)->next;
		free(new);
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

void ft_ra(t_stack **stack)
{
	if(*stack == NULL || (*stack)->next == NULL)
		return ;
	t_stack *new;
	t_stack *primeiro_no;

	new = malloc(sizeof(t_stack));
	primeiro_no = malloc(sizeof(t_stack));
	new = *stack;
	primeiro_no = new;
	while(new->next != NULL)
		new = new->next;
	new->next = primeiro_no;
	*stack = (*stack)->next;
	primeiro_no->next = NULL;
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

void ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if(*stack_a == NULL)
		return;
	adicionar_inicio(stack_b,(*stack_a)->valor);
	remover_primeiro(stack_a);
	
}


void ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	if(*stack_b == NULL)
		return ;
	adicionar_inicio(stack_a,(*stack_b)->valor);
	remover_primeiro(stack_b);
}

int organizar(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	if((*stack_a)->valor > (*stack_a)->next->valor) //se tirar os comentarios a logica dos 3 funciona mas dos 5 falha
		//&& ((valor_do_ultimo(*stack_a) > (*stack_a)->valor
		//	|| valor_do_ultimo(*stack_a) < (*stack_a)->next->valor)))
	{
		ft_sa(stack_a);
		ft_printf("sa\n");
		i++;
	}
	else if(valor_do_ultimo(*stack_a) < (*stack_a)->valor
		|| (valor_do_ultimo(*stack_a) > (*stack_a)->valor
			&& valor_do_ultimo(*stack_a) < (*stack_a)->next->valor))
	{
		if((*stack_a)->valor < (*stack_a)->next->valor)
		{
			ft_rra(stack_a);
			ft_printf("rra\n");
			i++;
		}
		else
		{
			ft_ra(stack_a);
			ft_printf("ra\n");
			i++;
		}
	}
	else if(verificar_organizado(*stack_a) == 1)
	{
		ft_pa(stack_a,stack_b);
		ft_printf("pb\n");
		i++;
	}
	else
	{
		ft_pa(stack_b,stack_a);
		ft_printf("pa\n");
		i++;
	}

	//agora na parte do B
	//depois tentar juntar ? para comecar a usar o ss por exemplo
	if(*stack_b && (*stack_b)->next)
	{
		if((*stack_b)->valor < (*stack_b)->next->valor)
		{
			ft_sa(stack_b);
			ft_printf("sb\n");
			i++;
		}
		else if(valor_do_ultimo(*stack_b) > (*stack_b)->valor)
		{
			if((*stack_b)->valor > (*stack_b)->next->valor)
			{
				ft_rra(stack_b);
				ft_printf("rrb\n");
				i++;
			}
			else
			{
				ft_ra(stack_b);
				ft_printf("rb\n");
				i++;
			}
			
		}
		/*else
		{
			ft_pa(stack_b,stack_a);
			ft_printf("pa\n");
			i++;
		}*/

	}
	return(i);
}

int verificar_stack_b(t_stack *stack)
{
	if(stack == NULL)
		return 0;
	return 1;
}

void organizar_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	while(1)
	{
		if((verificar_organizado(*stack_a)) == 0 && verificar_stack_b(*stack_b) == 0)
			break;
		else
			i += organizar(stack_a,stack_b);
	}
	printf("organizou em %d passos\n\n",i);
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
	/*ft_printf("\nstack_a:\n");
	printar_struct(stack_a);
	ft_printf("stack_b:\n");
	printar_struct(stack_b);*/
}
