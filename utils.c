/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperez <rodperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:14 by rodperez          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:21 by rodperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*return_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_smallest(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->n < smallest)
		{
			smallest = stack->n;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

int	stack_size(t_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	all_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\f' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\t' && str[i] != '\v')
			return (0);
		i++;
	}
	return (1);
}
