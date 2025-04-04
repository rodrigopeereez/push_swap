/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperez <rodperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:14 by rodperez          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:21 by rodperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*joined_args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	joined_args = join_args(argc, argv);
	if (!joined_args || joined_args[0] == '\0' || all_spaces(joined_args))
		return (free(joined_args), write(2, "Error\n", 6), 1);
	argv = ft_split(joined_args, ' ');
	free(joined_args);
	stack_init(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}
