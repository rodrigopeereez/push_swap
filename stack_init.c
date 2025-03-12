/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperez <rodperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:14 by rodperez          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:30 by rodperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *top)
{
	if (top == NULL)
		return (NULL);
	while (top->next)
		top = top->next;
	return (top);
}
//append_node reserva y enlaza cada nuevo node
static void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->n = nbr;
	node->cheapest = false;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static long	ft_atol(const char *str)
{
	long	n;
	int		i;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		&& str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + n * 10;
		i++;
	}
	return (n * neg);
}

/*Esta función recorre los argumentos ya divididos y,
tras validar la sintaxis y comprobar que no haya repeticiones
(usando funciones de error en free_errors.c), va creando los nodos
y agregándolos a la pila A. Aquí se usa una función auxiliar
append_node para reservar y enlazar cada nuevo nodo
([stack_init.c stack_init]).*/

void	stack_init(t_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a, argv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a, argv);
		if (error_repetition(*a, (int)nbr))
			free_error(a, argv);
		append_node(a, (int)nbr);
		i++;
	}
	free_matrix(argv);
}
