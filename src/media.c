/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:52:25 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:52:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_media_len(t_len *len, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL
		&& i < (((len->len_geral / 2) * len->elementos_stack)) - 1)
	{
		i++;
		stack = stack->next;
	}
	len->media = stack->valor;
}

int	encontrar_media(t_stack *stack, int media)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->valor == media)
			return (1);
		temp = temp->next;
	}
	return (0);
}
