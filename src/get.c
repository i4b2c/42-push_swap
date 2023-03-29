/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:53:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 19:53:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void get_len(t_len *len,int ac)
{
	int raiz;
	ft_raiz(&raiz,ac);
	len->raiz = raiz;
	len->divisao_stack = ac/(raiz);
	len->elementos_stack = ac/len->divisao_stack;
	len->ultimo_elementos = (len->elementos_stack+ac-(len->elementos_stack*len->divisao_stack));
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
		temp->next = NULL;
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
