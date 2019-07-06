/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:47:04 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 12:20:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_length_stack(t_stack *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

void	ft_free_stacks(t_ps **to_del)
{
	t_ps *stacks;

	if (to_del)
	{
		stacks = *to_del;
		ft_delstack(&stacks->a);
		ft_delstack(&stacks->b);
		ft_strdel(&stacks->line);
		free(stacks);
		to_del = NULL;
	}
}
