/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:02:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 13:45:35 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *list, t_vals *val, char *op)
{
	int		temp;

	if (list && list->next)
	{
		temp = list->num;
		list->num = list->next->num;
		list->next->num = temp;
	}
	if (val && !(val->line = ft_strjoin_f(val->line, op)))
		ft_exit(MALLOC_FAILURE);
}

void	ft_swap_two(t_stack *stack_a, t_stack *stack_b, t_vals *val, char *op)
{
	ft_swap(stack_a, val, op);
	ft_swap(stack_b, val, op);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, t_vals *val, char *op)
{
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	if (a && b)
	{
		ft_addnew(&b, a->num);
		ft_delonelist(&a);
		*stack_a = a;
		*stack_b = b;
	}
	else if (a && !b)
	{
		b = ft_newlist(a->num);
		ft_delonelist(&a);
		*stack_a = a;
		*stack_b = b;
	}
	if (val && !(val->line = ft_strjoin_f(val->line, op)))
		ft_exit(MALLOC_FAILURE);
}

void	ft_rotate(t_stack **stack_a, t_vals *val, char *op)
{
	t_stack *temp;
	int		first_num;

	temp = *stack_a;
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
	if (val && !(val->line = ft_strjoin_f(val->line, op)))
		ft_exit(MALLOC_FAILURE);
}

void	ft_rotate_two(t_stack **stack_a, t_stack **stack_b,\
		t_vals *val, char *op)
{
	ft_rotate(stack_a, val, op);
	ft_rotate(stack_b, val, op);
}
