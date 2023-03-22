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
//nao consegui colocar esta funcao para funcionar
/*
void get_geral (t_geral **geral,t_stack *stack, t_len len)
{
	int div;
	int ini;
	int tamanho;
	t_geral *temp;
	*geral = malloc(sizeof(t_geral));
	temp = *geral;
	tamanho = tamanho_stack(stack);
	if(stack != NULL)
	{
		ini = 1;
		div = 0;
		while(stack->next != NULL)
		{
			printf("tamanho:%d\n",tamanho);
			if(ini != len.divisao_stack)
				div = len.elementos_stack;
			else
				div = (len.elementos_stack+len.ac-(len.divisao_stack*len.elementos_stack));
			if(ini != 1)
				temp = malloc(sizeof(t_geral));
			printf("%d\n",ini);
			printf("%d\n",len.ac);
			printf("%d\n",len.elementos_stack);
			printf("%d\n",len.divisao_stack);
			printf("%d\n",div);
			printf("%d\n",(len.elementos_stack+len.ac-(len.divisao_stack*len.elementos_stack)));
			tamanho -= div;
			while(div > 0 && stack->next != NULL)
			{
				printf("%d",div);
				adicionar_fim(&temp->stack,stack->valor);
				temp->stack = temp->stack->next;
				div--;
				stack = stack->next;
				printf("ok");
			}
			if(stack->next == NULL)
			{
				printf("%d",div);
				adicionar_fim(&temp->stack,stack->valor);
				temp->stack = temp->stack->next;
				printf("ok");
			}
			if(stack == NULL)
			{
				printf("ue");
				return ;
			}
			printf("\n");
			temp = temp->next;
			stack = stack->next;
			ini++;
		}
	}
}
*/

void get_geral_dividido(t_geral **geral, t_stack *stack , t_len len)
{
	int raio;
	int elementos;
	int count;
	t_geral *novo;
	t_geral *temp;
	int i;

	elementos = len.elementos_stack;
	raio = len.raiz;
	count = 0;
	novo = *geral;
	while(count < raio)
	{
		temp = malloc(sizeof(t_geral));
		i = elementos;
		while(i > 0)
		{
			if(stack != NULL)
			{
				adicionar_fim(&temp->stack,stack->valor);
				printf("%d ",stack->valor);
				stack = stack->next;
			}
			i--;
		}
		printf("\n");
		novo = temp;
		temp = temp->next;
		novo = novo->next;
		count++;
	}
}
//tenta fazer assim
//chat gpt me ajudou , mas ainda nao esta certo , tentar arrumar depois
void dividir_em_tres(t_geral **geral, t_stack *stack) {
    t_geral *atual = *geral;
    t_stack *pilha_atual = stack;
    int count = 0;
    int i = 0;

    while (pilha_atual != NULL) {
        if (count % 2 == 0) {
            // criar um novo nó t_geral e atribuir a pilha atual
            t_geral *novo_geral = malloc(sizeof(t_geral));
            novo_geral->stack = pilha_atual;
            novo_geral->next = NULL;
	    /*if(count != 0)
	    {
		    if(stack->next->next)
	    		stack = stack->next->next;
			else if(stack->next)
				stack = stack->next;
	}*/
	    //avancar_pilha()


            // se a lista geral estiver vazia, atualize o cabeçalho
	    i = 0;
            if (*geral == NULL) {
                *geral = novo_geral;
                atual = novo_geral;
            } else {
                // caso contrário, adicione o novo nó ao final da lista geral
                atual->next = novo_geral;
                atual = novo_geral;
            }
        }

        // atualizar a pilha atual e contador
        pilha_atual = pilha_atual->next;
        count++;
    }
}


static void teste_geral(t_geral *geral)
{
	if(geral != NULL)
	{
		while(geral->next != NULL)
		{
			while(geral->stack->next != NULL)
			{
				ft_printf("%d\n",geral->stack->valor);
				geral->stack = geral->stack->next;
			}
			ft_printf("%d\n",geral->stack->valor);
			geral = geral->next;
			ft_printf("ok\n");
		}
	}
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
			printf("\n");
			geral = geral->next;
		}
	}
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
	dar_valor_a(&stack,av);
	replicar_struct(&replica_stack,stack);
	get_stack(&len,ac-1);
	//get_geral(&geral,stack,len);
	//dividir_em_tres(&geral,stack);
	get_geral_dividido(&geral,stack,len);
	printar_geral(geral);
	//teste_geral(geral);
	//teste_struct(stack,replica_stack,len);
}
