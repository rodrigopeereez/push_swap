/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rot.                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperez <rodperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:14 by rodperez          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:21 by rodperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Lleva el último nodo a la cima de la pila con rra, rrb y rrr 
(rotaciones inversas) easyyyyy ezzz*/

static void	reverse_rot(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_node **a, bool print)
{
	reverse_rot(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool print)
{
	reverse_rot(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, bool print)
{
	reverse_rot(a);
	reverse_rot(b);
	if (print)
		write(1, "rrr\n", 4);
}
