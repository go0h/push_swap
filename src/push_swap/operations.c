/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:19:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/02 01:02:06 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_operation(t_ps *stacks, char *oper)
{
	if (!(ft_strcmp("sa", oper)))
	{
		ft_printf("swap a\n");
		ft_swap(stacks, 'a');
	}
	else if (!(ft_strcmp("sb", oper)))
	{
		ft_printf("swap b\n");
		ft_swap(stacks, 'b');
	}
	else if (!(ft_strcmp("ss", oper)))
	{
		ft_printf("swap a and b\n");
		ft_swap_two(stacks);
	}
	else if (!(ft_strcmp("pa", oper)))
	{
		ft_printf("push a -> b\n");
		ft_push(stacks, 'a');
	}
	else if (!(ft_strcmp("pb", oper)))
	{
		ft_printf("push b -> a\n");
		ft_push(stacks, 'b');
	}
	else if (!(ft_strcmp("ra", oper)))
	{
		ft_printf("rotate a\n");
		ft_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rb", oper)))
	{
		ft_printf("rotate b\n");
		ft_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rr", oper)))
	{
		ft_printf("rotate a and b\n");
		ft_rotate_two(stacks);
	}
	else if (!(ft_strcmp("rra", oper)))
	{
		ft_printf("reverse rotate a\n");
		ft_rev_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rrb", oper)))
	{
		ft_printf("reverse rotate b\n");
		ft_rev_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rrr", oper)))
	{
		ft_printf("reverse rotate a and b\n");
		ft_rev_rotate_two(stacks);
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

int		ft_get_last_num(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
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
