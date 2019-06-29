/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 13:59:53 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, t_vals *val_s);;

void		ft_solver(t_stack **stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vals	*val_s;
	int		i;
	
	stack_b = NULL;
	stack_a = *stack;
	val_s = ft_gen_vals(stack_a);
	ft_split_med(&stack_a, &stack_b, val_s);
	while (val_s->len > 1)
	{
		while (ft_get_length_stack(stack_b) != 1)
			ft_get_half_stack(&stack_b, &stack_a, val_s);
		ft_push(&stack_b, &stack_a, val_s, "pa\n");
		ft_rotate(&stack_a, val_s, "ra\n");
		val_s->len--;
		val_s->med = ft_get_mediana(stack_a, val_s->len);
		i = val_s->len;
		while (i--)
			ft_push(&stack_a, &stack_b, val_s, "pb\n");
	}
	ft_push(&stack_b, &stack_a, val_s, "pb\n");
	ft_rotate(&stack_a, val_s, "ra\n");
	ft_printstacks(stack_a, stack_b);
//	ft_printf("%s", val_s->line);
	*stack = stack_a;
}

void	ft_split_med(t_stack **s_a, t_stack **s_b, t_vals *val_s)
{
	t_stack	*stack_a;
	int		len;
	
	stack_a = *s_a;
	len = (val_s->len % 2 == 1 && val_s->len != 1) ? val_s->len / 2 + 1 : val_s->len / 2;
	while (len)
	{
		if (stack_a && stack_a->num <= val_s->med)
		{
			ft_push(&stack_a, s_b, val_s, "pb\n");
			--len;
		}
		else
			ft_rotate(&stack_a, val_s, "ra\n");
		ft_printstacks(stack_a, *s_b);
	}
	*s_a = stack_a;
}

void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, t_vals *val_s)
{
	int		med;
	int		len;
	t_stack *stack_a;

	stack_a = *s_a;
	len = ft_get_length_stack(stack_a) / 2;
	med = ft_get_mediana(stack_a, ft_get_length_stack(stack_a));
	while (len)
	{
		if (stack_a && stack_a->num <= med)
			ft_rev_rotate(&stack_a, val_s, "rrb\n");
		else
		{
			ft_push(&stack_a, s_b, val_s, "pa\n");
			--len;
		}
		ft_printstacks(*s_b, stack_a);
	}
	ft_printstacks(*s_b, stack_a);
	*s_a = stack_a;
}
