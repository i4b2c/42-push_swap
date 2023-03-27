/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniciar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:30:21 by marvin            #+#    #+#             */
/*   Updated: 2023/03/27 20:30:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void dar_valor_a(t_stack **stack,char **av)
{
	int i;

	i = 1;
	while(av[i] != NULL)
	{
		adicionar_fim(stack,ft_atoi(av[i]));
		i++;
	}
}
