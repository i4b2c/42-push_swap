#include "push_swap.h"

void colocar_numero(int *num,int len)
{
	int i;
	int c;
	len--;

	c = len-1;
	i = 0;
	while(c >= 0)
	{
		ft_printf("%d\n",num[i]);
		i++;
		c--;
	}
}

void iniciar_stack_b(int *stack_b, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		stack_b[i] = 0;
		i++;
	}
}

void valor_numero(int *num, int ac, char **av)
{
	int i;
	i = 0;
	while(i < ac)
	{
		num[i] = ft_atoi(av[i+1]);
		i++;
	}
}

void sa(int *stack_a)
{
	int temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}

void sb(int *stack_b)
{
	int temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}

void ss(int *stack_a,int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void avancar(int *stack,int len)
{
	int i;
	i = 0;
	while(i < len-1)
	{
		stack[i] = stack[i+1];
		i++;
	}
	stack[i] = 0;
}

void r_avancar(int *stack,int len)
{
	int i;
	i = len-1;
	while(i > 0)
	{
		stack[i] = stack[i-1];
		i--;
	}
	stack[0] = 0;
}

void pa(int *stack_a,int*stack_b,int len)
{
	if(stack_b[0])
	{
		r_avancar(stack_a,len);
		stack_a[0] = stack_b[0];
	}
	avancar(stack_b,len);
}

void pb(int *stack_a,int*stack_b,int len)
{
	if(stack_a[0])
	{
		r_avancar(stack_b,len);
		stack_b[0] = stack_a[0];
	}
	avancar(stack_a,len);
}

void ra(int *stack_a,int len)
{
	int temp;
	int i;

	i = 0;
	temp = stack_a[0];
	while(i<len-1)
	{
		stack_a[i] = stack_a[i+1];
		i++;
	}
	stack_a[i] = temp;
}

void rra(int *stack_a,int len)
{
	int temp;
	int i;
	temp = stack_a[len-1];
	i = len-1;
	while(i > 0)
	{
		stack_a[i] = stack_a[i-1];
		i--;
	}
	stack_a[i] = temp;
}

int organizar_numero(int *stack_a, int *stack_b, int ac)
{
	int i;
	int n;
	(void)stack_b;
	(void)ac;
	n = 0;
	i = 0;
	while(stack_a[i])
	{
		if(stack_a[0] > stack_a[1])
		{
			sa(stack_a);
			n++;
		}
		i++;
	}
	return (n);
}

void colocar_stacks(int *stack_a,int *stack_b, int ac)
{
	printf("\nStack A:\n\n");
	colocar_numero(stack_a,ac);
	printf("\nStack B:\n\n");
	colocar_numero(stack_b,ac);
	printf("\n");
}

int main(int ac, char **av)
{
	int *stack_a;
	int *stack_b;
	int len_org;

	len_org = 0;
	if(ac != 1)
	{
		stack_a = (int *)malloc(sizeof(int *) * ac + 1);
		stack_b = (int *)malloc(sizeof(int *) * ac + 1);
		valor_numero(stack_a,ac-1,av);
		iniciar_stack_b(stack_b,ac-1);
		//len_org = organizar_numero(stack_a,stack_b,ac-1);
		colocar_stacks(stack_a,stack_b,ac);
		free(stack_a);
		free(stack_b);
		ft_printf("quantidade : %d\n",len_org);
	}
	return(0);
}
