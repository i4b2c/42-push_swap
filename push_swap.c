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

int main(int ac, char **av)
{
	int *num;
	int i;
	int temp;
	(void)av;

	i = 0;
	num = (int *)malloc(sizeof(int *) * ac + 1);
	if(ac != 1)
	{
		while(i+1 < ac)
		{
			num[i] = ft_atoi(av[i+1]);
			i++;
		}
		i = 0;
		while(i+1 < ac)
		{
			if(num[i] > num[i+1] && i+2 < ac)
			{
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
				i = -1;
			}
			//ft_printf("%d\n",num[i]);
			i++;
		}
		colocar_numero(num);
		free(num);
	}
	//printf("\n");
	return(0);
}
