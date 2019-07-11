/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:27:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/10 23:36:49 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rev_rotate(t_ps *stacks, char cur)
{
	t_stack *temp;

	temp = cur == 'a' ? stacks->a : stacks->b;
	if (temp && temp->next)
	{
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = (cur == 'a' ? stacks->a : stacks->b);
		if (cur == 'a')
			stacks->a = temp->next;
		else
			stacks->b = temp->next;
		temp->next = NULL;
	}
	stacks->line[stacks->i] = cur == 'a' ? RRA : RRB;
	stacks->i += 1;
	return (1);
}

int		ft_rev_rotate_two(t_ps *stacks)
{
	ft_rev_rotate(stacks, 'a');
	ft_rev_rotate(stacks, 'b');
	return (1);
}
