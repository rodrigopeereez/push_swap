/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperez <rodperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:14 by rodperez          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:21 by rodperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Define las operaciones pa y pb que mueven el nodo superior
de una pila a otra. La función interna push se encarga de ajustar
los punteros y mantener la integridad de la lista doblemente enlazada*/

static void	push(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	tmp->prev = NULL;
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
