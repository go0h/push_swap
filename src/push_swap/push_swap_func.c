/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:02:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 17:34:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap(t_ps *stacks, char cur)
{
	int		temp;
	t_stack	*list;

//	ft_printf("swap %c\n", cur);
	list = cur == 'a' ? stacks->a : stacks->b;
	if (list && list->next)
	{
		temp = list->num;
		list->num = list->next->num;
		list->next->num = temp;
	}
	if (!(stacks->line = ft_strjoin_f(stacks->line,\
		cur == 'a' ? "sa\n" : "sb\n")))
		ft_exit(&stacks, MALLOC_FAILURE);
//	ft_printstacks(stacks->a, stacks->b);
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

//	ft_printf("push %c\n", cur);
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
	if (!(stacks->line = ft_strjoin_f(stacks->line,\
		cur == 'a' ? "pa\n" : "pb\n")))
		ft_exit(&stacks, MALLOC_FAILURE);
//	ft_printstacks(stacks->a, stacks->b);
	return (1);
}

int		ft_rotate(t_ps *stacks, char cur)
{
	t_stack *temp;
	int		first_num;

//	ft_printf("rorate %c\n", cur);
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
	if (!(stacks->line = ft_strjoin_f(stacks->line,\
		cur == 'a' ? "ra\n" : "rb\n")))
		ft_exit(&stacks, MALLOC_FAILURE);
//	ft_printstacks(stacks->a, stacks->b);
	return (1);
}

int		ft_rotate_two(t_ps *stacks)
{
	ft_rotate(stacks, 'a');
	ft_rotate(stacks, 'b');
	return (1);
}
