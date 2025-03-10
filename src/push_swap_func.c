/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:02:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/13 12:06:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap(t_ps *stacks, char cur)
{
	int		temp;
	t_stack	*list;

	list = cur == 'a' ? stacks->a : stacks->b;
	if (list && list->next)
	{
		temp = list->num;
		list->num = list->next->num;
		list->next->num = temp;
	}
	stacks->line[stacks->i] = cur == 'a' ? SA : SB;
	stacks->i += 1;
	stacks->v ? ft_print_stack(stacks) : 0;
	return (1);
}

int		ft_swap_two(t_ps *stacks)
{
	ft_swap(stacks, 'a');
	ft_swap(stacks, 'b');
	return (1);
}

int		ft_push(t_ps *stacks, char cur)
{
	t_stack *temp;

	temp = cur == 'a' ? stacks->b : stacks->a;
	if (cur == 'a' && stacks->b)
	{
		stacks->b ? stacks->b = stacks->b->next : 0;
		temp->next = stacks->a;
		stacks->a = temp;
	}
	else if (cur == 'b' && stacks->a)
	{
		stacks->a ? stacks->a = stacks->a->next : 0;
		temp->next = stacks->b;
		stacks->b = temp;
	}
	stacks->line[stacks->i] = cur == 'a' ? PA : PB;
	stacks->i += 1;
	stacks->v ? ft_print_stack(stacks) : 0;
	return (1);
}

int		ft_rotate(t_ps *stacks, char cur)
{
	t_stack *temp;
	int		first_num;

	temp = cur == 'a' ? stacks->a : stacks->b;
	if (temp)
	{
		first_num = temp->num;
		while (temp->next)
		{
			temp->num = temp->next->num;
			temp = temp->next;
		}
		temp->num = first_num;
	}
	stacks->line[stacks->i] = cur == 'a' ? RA : RB;
	stacks->i += 1;
	stacks->v ? ft_print_stack(stacks) : 0;
	return (1);
}

int		ft_rotate_two(t_ps *stacks)
{
	ft_rotate(stacks, 'a');
	ft_rotate(stacks, 'b');
	return (1);
}
