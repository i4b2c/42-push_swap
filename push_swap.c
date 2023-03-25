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
	if(!stack)
		return 1;
	while(stack->next != NULL)
	{
		if(stack->valor >= stack->next->valor)
			return 1;
		stack = stack->next;
	}
	return (0);
}

int verificar_organizado_b(t_stack *stack)
{
	while(stack->next != NULL)
	{
		if(stack->valor <= stack->next->valor)
			return 1;
		stack = stack->next;
	}
	return 0;
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
	if(*stack_b && (*stack_b)->next)
	{
		if((*stack_a)->valor > (*stack_a)->next->valor
			&& (*stack_b)->valor < (*stack_b)->next->valor)
		{
			ft_sa(stack_a);
			ft_sa(stack_b);
			ft_printf("ss\n");
			i++;
		}
		else if((valor_do_ultimo(*stack_a) < (*stack_a)->valor)
			&& valor_do_ultimo(*stack_b) > (*stack_b)->valor)
		{
			if((*stack_a)->valor < (*stack_a)->next->valor
				&& (*stack_b)->valor > (*stack_b)->next->valor)
			{
				ft_rra(stack_a);
				ft_rra(stack_b);
				ft_printf("rrr\n");
				i++;
			}
			else if((*stack_a)->valor > (*stack_a)->next->valor
				&& (*stack_b)->valor < (*stack_b)->next->valor)
			{
				ft_ra(stack_a);
				ft_ra(stack_b);
				ft_printf("rr\n");
				i++;
			}
		}
	}
	if((*stack_a)->valor > (*stack_a)->next->valor
		&& ((valor_do_ultimo(*stack_a) > (*stack_a)->valor
			|| valor_do_ultimo(*stack_a) < (*stack_a)->next->valor)))
	{
		ft_sa(stack_a);
		ft_printf("sa\n");
		i++;
	}
	else if((valor_do_ultimo(*stack_a) < (*stack_a)->valor))
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
	else if(!((*stack_a)->valor > (*stack_a)->next->valor)
		&& !((valor_do_ultimo(*stack_a) < (*stack_a)->valor))
		&& verificar_organizado(*stack_a) == 1)
	{
		ft_pa(stack_a,stack_b);
		ft_printf("pb\n");
		i++;
	}
	if(*stack_b)
	{
		if((*stack_b)->next && (*stack_b)->valor < (*stack_b)->next->valor)
		{
			ft_sa(stack_b);
			ft_printf("sb\n");
			i++;
		}
		else if((*stack_b)->next && valor_do_ultimo(*stack_b) > (*stack_b)->valor)
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
		else if(verificar_organizado(*stack_a) == 0)
		{
			ft_pa(stack_b,stack_a);
			ft_printf("pa\n");
			i++;
		}
	}
	return(i);
}

int organizar_3(t_stack **stack_a)
{
	int i;
	i = 0;
	if((*stack_a)->valor > (*stack_a)->next->valor
		&& ((valor_do_ultimo(*stack_a) > (*stack_a)->valor
			|| valor_do_ultimo(*stack_a) < (*stack_a)->next->valor)))
	{
		ft_sa(stack_a);
		ft_printf("sa\n");
		i++;
	}
	else if((valor_do_ultimo(*stack_a) < (*stack_a)->valor)
		|| (valor_do_ultimo(*stack_a) > (*stack_a)->valor
			&& (*stack_a)->next->valor > (*stack_a)->valor))
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
	return i;
}

void organizar_stack_3(t_stack **stack_a)
{
	int i;
	i = 0;
	while(1)
	{
		if((verificar_organizado(*stack_a)) == 0)
			break;
		else
			i += organizar_3(stack_a);
	}
	printf("organizou em %d passos\n",i);
}

void organizar_stack_5(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	i = 0;
	(void)stack_a;
	(void)stack_b;
	while(1)
	{
		break;
	}
	printf("organizou em %d passos\n",i);
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
	printf("organizou em %d passos\n",i);
}

void ft_raiz(int *raiz,int ac)
{
	int i;
	i = 0;
	ac--;
	while(1)
	{
		if(i * i >= ac)
		{
			*raiz = i;
			return ;
		}
		i++;
	}
}

/*
void dividir_stacks_maior(t_stack **stack,int ac)
{
	int raiz;
	double stack_dividido;
	double num_elementos;
	ft_raiz(&raiz,ac);
	printf("raiz:%d\n",raiz);
	stack_dividido = ac/(raiz+(raiz/4));
	num_elementos = ac/stack_dividido;
	printf("stack vai ser dividido em:%d\n",(int)stack_dividido);
	printf("num de elementos:%f\n",num_elementos);
}*/

int verificar_valor_na_stack(t_stack *stack, int valor)
{
	while(stack != NULL)
	{
		if(stack->valor == valor)
			return 1;
		stack = stack->next;
	}
	return 0;
}

void dividir_stack_b(t_stack **stack_a , t_stack **stack_b,t_geral **geral , t_len len)
{
	t_geral *temp;
	int i;
	int len_d;

	temp = *geral;
	i = 0;
	len_d = 0;
	while(temp != NULL && *stack_a != NULL)
	{
		if(*stack_a)
		{
			if (verificar_valor_na_stack(temp->stack, (*stack_a)->valor) == 1) {
				ft_pa(stack_a, stack_b);
				printf("pb\n");
				i++;
			} else {
					ft_ra(stack_a);
					printf("ra\n");
				//depois tenta aplicar a logica do ra e rra , apesar do ra ter um desempenho melhor
			}
		}
		if(i == len.elementos_stack)
		{
			if(len_d + 1 != len.divisao_stack)
			{
				temp = temp->next;
				i = 0;
			}
			len_d++;
		}
	}
	ft_pa(stack_a, stack_b);
	printf("pb\n");
}
/*
void organizar_stack_b_a(t_stack **stack_a, t_stack **stack_b, t_len len)
{
	int i;
	int cont;

	i = 0;
	while(stack_b != NULL)
	{
		while(i <= len.divisao_stack)
		{
			if(i == 0)
				cont = len.ultimo_elementos;
			else
				cont = len.elementos_stack;
			while(cont > 0)
			{
				//if()
				break;
			}
		}
		i++;
	}
}
*/

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *replica_stack;
	t_geral *geral;
	t_len len;
	len.ac = ac-1;
	stack_a = NULL;
	stack_b = NULL;
	geral = NULL;
	replica_stack = NULL;
	if(len.ac >= 3 && verificar_repitida(av) == 0)
	{
		dar_valor_a(&stack_a,av);
		get_len(&len,ac-1);
		replicar_struct(&replica_stack,stack_a);
		organizar_replica(&replica_stack);
		get_geral_dividido(&geral,replica_stack,len);
		dividir_stack_b(&stack_a,&stack_b,&geral,len);
		start_organizar(&stack_a,&stack_b);
		//organizar_stack_b_a(&stack_a,&stack_b,len);
	}
}
