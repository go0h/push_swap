/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:27:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 13:44:52 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **stack_a, t_vals *val, char *op)
{
	t_stack *temp;

	temp = *stack_a;
	if (temp && temp->next)
	{
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stack_a;
		*stack_a = temp->next;
		temp->next = NULL;
	}
	if (val && !(val->line = ft_strjoin_f(val->line, op)))
		ft_exit(MALLOC_FAILURE);
}

void	ft_rev_rotate_two(t_stack **stack_a, t_stack **stack_b,\
		t_vals *val, char *op)
{
	ft_rev_rotate(stack_a, val, op);
	ft_rev_rotate(stack_b, val, op);
}
