/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:58:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/29 02:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_while(t_stack **stack)
{
	while ((*stack) != NULL)
	{
		remover_primeiro(stack);
	}
}

void	free_geral(t_geral **geral)
{
	t_geral	*temp;

	temp = NULL;
	while ((*geral) != NULL)
	{
		temp = (*geral)->next;
		free_while(&(*geral)->stack);
		free ((*geral));
		(*geral) = temp;
	}
}

void	free_todos(t_stack **stack_a, t_stack **replica, t_geral **geral)
{
	free_while(stack_a);
	free_while(replica);
	free_geral(geral);
}
