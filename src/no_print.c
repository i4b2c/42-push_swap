/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:58:06 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:58:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra_no_print(t_stack **stack)
{
	t_stack	*new;
	t_stack	*primeiro_no;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = *stack;
	primeiro_no = new;
	while (new->next != NULL)
		new = new->next;
	new->next = primeiro_no;
	*stack = (*stack)->next;
	primeiro_no->next = NULL;
}

void	ft_rra_no_print(t_stack **stack)
{
	t_stack	*new;
	t_stack	*ultimo_no;
	t_stack	*penultimo_no;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = *stack;
	while (new->next != NULL)
	{
		if (new->next != NULL && new->next->next == NULL)
			penultimo_no = new;
		new = new->next;
	}
	ultimo_no = new;
	penultimo_no->next = NULL;
	ultimo_no->next = *stack;
	*stack = ultimo_no;
}
