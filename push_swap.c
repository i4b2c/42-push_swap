#include "push_swap.h"

int main(int ac, char **av)
{
	int *num;
	int i;

	i = 0;
	num = (int *)malloc(sizeof(int *) * ac + 1);
	if(ac != 1)
	{
		while(i+1 < ac)
		{
			num[i] = ft_atoi(av[i+1]);	
			printf("%d\n",num[i]);
			i++;
		}
		free(num);
	}
	//printf("\n");
	return(0);
}
