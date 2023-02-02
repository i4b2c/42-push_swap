#include "push_swap.h"

void colocar_numero(int *num)
{
	int i;

	i = 0;
	while(num[i])
	{
		ft_printf("%d\n",num[i]);
		i++;
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

void sa(int *num)
{
	int temp;

	temp = num[0];
	num[0] = num[1];
	num[1] = temp;
}

int main(int ac, char **av)
{
	int *stack_a;
	int *stack_b;

	if(ac != 1)
	{
		stack_a = (int *)malloc(sizeof(int *) * ac + 1);
		stack_b = (int *)malloc(sizeof(int *) * ac + 1);
		valor_numero(stack_a,ac,av);
		if(stack_a[0] > stack_a[1])
			sa(stack_a);
		colocar_numero(stack_a);
		free(stack_a);
		free(stack_b);
	}
	return(0);
}
