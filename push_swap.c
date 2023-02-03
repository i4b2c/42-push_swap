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

void valor_numero(int *num, int ac, char **av)
{
	int i;
	i = 0;
	while(i+1 < ac)
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

void ra(int *stack_a,int len)
{
	int temp;
	int i;
	len--;
	temp = stack_a[len-1];
	i = len-1;
	while(i > 0)
	{
		stack_a[i] = stack_a[i-1];
		i--;
	}
	stack_a[i] = temp;
}


/*
void ra(int *stack_a,int len)
{
	int temp1;
	int temp2;
	int temp_len;
	int i;
	i = 0;
	len--;
	temp_len = stack_a[len-1];
	while(stack_a[i] && i+1 < len)
	{
		if(i == 0)
		{
			temp1 = stack_a[i+1];
			stack_a[i+1] = stack_a[i];
		}
		else if(i % 2 != 0)
		{
			temp2 = stack_a[i+1];
			stack_a[i] = temp1;
		}
		else if(i % 2 == 0)
		{
			temp1 = stack_a[i+1];
			stack_a[i] = temp2;
		}
		i++;
	}
	stack_a[0] = temp_len;
}*/
		


int main(int ac, char **av)
{
	int *stack_a;
	int *stack_b;

	if(ac != 1)
	{
		stack_a = (int *)malloc(sizeof(int *) * ac + 1);
		stack_b = (int *)malloc(sizeof(int *) * ac + 1);
		valor_numero(stack_a,ac,av);
		ra(stack_a,ac);
		colocar_numero(stack_a,ac);
		free(stack_a);
		free(stack_b);
	}
	return(0);
}
