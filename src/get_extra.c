/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:25:45 by marvin            #+#    #+#             */
/*   Updated: 2023/04/04 12:25:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	continua_atual(t_geral **atual, t_geral *temp)
{
	(*atual)->next = temp;
	*atual = (*atual)->next;
}

void	colocar_inicio(t_geral **novo, t_geral **atual, t_geral *temp)
{
	(*novo) = temp;
	(*atual) = *novo;
}

void	get_i(t_len len, int *i, int count)
{
	if (count == len.divisao_stack - 1)
		*i = len.elementos_stack
			+ (len.ac - (len.elementos_stack * len.divisao_stack));
	else
		*i = len.elementos_stack;
}

void	get_geral_iniciar(int *count, t_geral **novo, t_geral **atual)
{
	*count = 0;
	*novo = NULL;
	*atual = NULL;
}

void	criar_temp(t_geral **temp)
{
	(*temp) = malloc (sizeof(t_geral));
	(*temp)->stack = NULL;
	(*temp)->next = NULL;
}
