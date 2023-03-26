#include "push_swap.h"

void replicar_struct(t_stack **replica,t_stack *stack)
{
	if(stack != NULL)
	{
		while(stack->next != NULL)
		{
			adicionar_fim(replica,stack->valor);
			stack = stack->next;
		}
		adicionar_fim(replica,stack->valor);
	}
}

void get_geral_dividido(t_geral **geral, t_stack *stack , t_len len)
{
	int raio = len.divisao_stack;
	int elementos = len.ac/raio;
	int count = 0;
	t_geral *novo = NULL;
	t_geral *atual = NULL;
	t_geral *temp = NULL;
	int i;

	while(count < raio)
	{
		temp = malloc(sizeof(t_geral));
		temp->stack = NULL;
		if(count == raio-1)
			i = len.elementos_stack+(len.ac-(len.elementos_stack*len.divisao_stack));
		else
			i = elementos;
		while(i > 0)
		{
			if(stack != NULL)
			{
				adicionar_fim(&temp->stack,stack->valor);
				stack = stack->next;
			}
			i--;
		}
		if(novo == NULL)
		{
			novo = temp;
			atual = novo;
		}
		else
		{
			atual->next = temp;
			atual = atual->next;
		}
		count++;
	}
	*geral = novo;
}

/*
void printar_geral(t_geral *geral)
{
	if(geral != NULL)
	{
		while(geral->next != NULL)
		{
			while(geral->stack->next != NULL)
			{
				printf("%d ",geral->stack->valor);
				geral->stack = geral->stack->next;
			}
			printf("%d",geral->stack->valor);
			printf("\n");
			geral = geral->next;
		}
		while(geral->stack->next != NULL)
		{
			printf("%d ",geral->stack->valor);
			geral->stack = geral->stack->next;
		}
		printf("%d",geral->stack->valor);
		printf("\n");
	}
}*/

void printar_geral(t_geral **geral)
{
	t_geral *temp;
	temp = *geral;
	t_stack *stack_temp;
	if(temp != NULL)
	{
		while(temp != NULL)
		{
			stack_temp = temp->stack;
			while(stack_temp != NULL)
			{
				ft_printf("%d ",stack_temp->valor);
				stack_temp = stack_temp->next;
			}
			printf("\n");
			temp = temp->next;
		}
	}
}

void get_len(t_len *len,int ac)
{
	int raiz;
	ft_raiz(&raiz,ac);
	len->raiz = raiz;
	len->divisao_stack = ac/(raiz);
	len->elementos_stack = ac/len->divisao_stack;
	len->ultimo_elementos = (len->elementos_stack+ac-(len->elementos_stack*len->divisao_stack));
}

void organizar_replica(t_stack **stack)
{
	t_stack *temp;
	int temp_valor;

	temp = NULL;
	while(1)
	{
		temp = *stack;
		if(verificar_organizado(*stack)==0)
			break;
		else
		{
			while(temp->next != NULL)
			{
				if(temp->valor > temp->next->valor)
				{
					temp_valor = temp->valor;
					temp->valor = temp->next->valor;
					temp->next->valor = temp_valor;
				}
				temp = temp->next;
			}
		}
	}
}

long long int	ft_atoll(const char *str)
{
	long long int	result;
	int						sign;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((long long int)result * sign);
}

int verificar_repitida(char **str)
{
	long long int temp;

	int i;
	int j;

	i = 1;
	while(str[i] != NULL)
	{
		j = 1;
		temp = ft_atoll(str[i]);
		if(temp > INT_MAX || temp < INT_MIN)
			return 1;
		while(str[j] != NULL)
		{
			if(i != j && temp == ft_atoll(str[j]))
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}
/*
int main(int ac, char **av)
{
	t_stack *stack;
	t_stack *replica_stack;
	t_geral *geral;
	t_len len;
	len.ac = ac-1;
	stack = NULL;
	geral = NULL;
	replica_stack = NULL;
	if(len.ac >= 7 && verificar_repitida(av) == 0)
	{
		dar_valor_a(&stack,av);
		get_len(&len,ac-1);
		replicar_struct(&replica_stack,stack);
		organizar_replica(&replica_stack);
		get_geral_dividido(&geral,replica_stack,len);
		printar_geral(geral);
		dividir_stack_b()
		//teste_struct(stack,replica_stack,len);
	}
}
*/
