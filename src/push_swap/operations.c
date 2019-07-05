/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:19:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/05 20:29:23 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_operation(t_ps *stacks, char *oper, int flag)
{
	if (!(ft_strcmp("sa", oper)))
	{
		flag ? ft_printf("swap a\n") : 0;
		ft_swap(stacks, 'a');
	}
	else if (!(ft_strcmp("sb", oper)))
	{
		flag ? ft_printf("swap b\n") : 0;
		ft_swap(stacks, 'b');
	}
	else if (!(ft_strcmp("ss", oper)))
	{
		flag ? ft_printf("swap a and b\n") : 0;
		ft_swap_two(stacks);
	}
	else if (!(ft_strcmp("pa", oper)))
	{
		flag ? ft_printf("push a -> b\n") : 0;
		ft_push(stacks, 'a');
	}
	else if (!(ft_strcmp("pb", oper)))
	{
		flag ? ft_printf("push b -> a\n") : 0;
		ft_push(stacks, 'b');
	}
	else if (!(ft_strcmp("ra", oper)))
	{
		flag ? ft_printf("rotate a\n") : 0;
		ft_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rb", oper)))
	{
		flag ? ft_printf("rotate b\n") : 0;
		ft_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rra", oper)))
	{
		flag ? ft_printf("reverse rotate a\n") : 0;
		ft_rev_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rrb", oper)))
	{
		flag ? ft_printf("reverse rotate b\n") : 0;
		ft_rev_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rrr", oper)))
	{
		flag ? ft_printf("reverse rotate a and b\n") : 0;
		ft_rev_rotate_two(stacks);
	}
	else if (!(ft_strcmp("rr", oper)))
	{
		flag ? ft_printf("rotate a and b\n") : 0;
		ft_rotate_two(stacks);
	}
	else
		ft_exit(WRONG_OPERATION);
	return (1);
}

int		ft_check_sort(t_stack *stack_a, int len)
{
	int n;
	int i;

	i = 0;
	n = stack_a->num;
	stack_a = stack_a->next;
	while (stack_a && i < len)
	{
		if (n >= stack_a->num)
			return (0);
		n = stack_a->num;
		stack_a = stack_a->next;
		++i;
	}
	return (1);
}

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
