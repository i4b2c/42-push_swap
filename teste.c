#include "push_swap.h"

/*
typedef struct d_stack
{
	int valor;
	struct d_stack *next;
}	t_stack;
*/

//void adicionar_inicio(t_stack **stack, int valor)
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

static void teste_len(t_len len)
{
	ft_printf("len->\nac:%d\nraiz:%d\ndivisao:%d\nelementos:%d\n"
		,len.ac,len.raiz,len.divisao_stack,len.elementos_stack);
	ft_printf("calculo para ultimo:%d\n"
		,len.elementos_stack+len.ac-(len.divisao_stack*len.elementos_stack));
}

static void teste_struct(t_stack *principal, t_stack *replica, t_len len)
{
	(void)len;
	//printar_struct(principal);
	//teste_len(len);
	ft_printf("replica->\n");
	printar_struct(replica);
}

static int tamanho_stack(t_stack *stack)
{
	int i;
	i = 0;
	if(stack != NULL)
	{
		while(stack->next != NULL)
		{
			stack = stack->next;
			i++;
		}
		i++;
		return i;
	}
	return 0;
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

	while(count <= raio)
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

static void printar_geral(t_geral *geral)
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
	}
}

void get_len(t_len *len,int ac)
{
	int raiz;
	int raiz2;
	ft_raiz(&raiz,ac);
	ft_raiz(&raiz2,raiz);
	len->raiz = raiz;
	len->divisao_stack = ac/(raiz+raiz2/2);
	len->elementos_stack = ac/len->divisao_stack;
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

int verificar_repitida(char **str)
{
	int temp;

	int i;
	int j;

	i = 1;
	while(str[i] != NULL)
	{
		j = 1;
		temp = ft_atoi(str[i]);
		while(str[j] != NULL)
		{
			if(i != j && temp == ft_atoi(str[j]))
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

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
		//teste_struct(stack,replica_stack,len);
	}
}
