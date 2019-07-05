/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:27:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 00:07:31 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_ps *stacks, char cur)
{
	t_stack *temp;

//	ft_printf("reverse rotate %c\n", cur);
	temp = cur == 'a' ? stacks->a : stacks->b;
	if (temp && temp->next)
	{
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = (cur == 'a' ? stacks->a : stacks->b);
		if (cur == 'a')
			stacks->a  = temp->next;
		else
			stacks->b = temp->next;
		temp->next = NULL;
	}
	if (!(stacks->line = ft_strjoin_f(stacks->line,\
		cur == 'a' ? "rra\n" : "rrb\n")))
		ft_exit(MALLOC_FAILURE);
//	ft_printstacks(stacks->a, stacks->b);
}

void	ft_rev_rotate_two(t_ps *stacks)
{
	ft_rev_rotate(stacks, 'a');
	ft_rev_rotate(stacks, 'b');
}
