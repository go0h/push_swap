/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 18:05:12 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, t_vals *val_s);;
int			ft_split_med_b(t_stack **s_a, t_stack **s_b, t_vals *val, int len);

void		ft_solver(t_stack **stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vals	*val;
	
	stack_b = NULL;
	stack_a = *stack;
	val = ft_gen_vals(stack_a);
	ft_split_med_a(&stack_a, &stack_b, val, val->len);
	*stack = stack_a;
	ft_printstacks(stack_a, stack_b);
}

int			ft_split_med_a(t_stack **s_a, t_stack **s_b, t_vals *val, int len)
{
	t_stack	*stack_a;
	int		med;
	int		i;

	i = 0;	
	stack_a = *s_a;
	ft_printf("split_a: len = %d\n", len);
	if (ft_basic_case(&stack_a, val, len) == 1)
	{
		while (len > 0)
		{
			ft_rotate(&stack_a, val, "ra\n");
			--len;
		}
		return (1);
	}
	med = ft_get_mediana(stack_a, len);
	while (i < len / 2)
	{
		if (stack_a && stack_a->num <= med)
		{
			ft_push(&stack_a, s_b, val, "pb\n");
			++i;
		}
		else
			ft_rotate(&stack_a, val, "ra\n");
	}
	*s_a = stack_a;
	val->len /= 2;
	ft_split_med_b(s_a, s_b, val, val->len);
	ft_split_med_a(s_a, s_b, val, val->len);
	return (0);
}

int			ft_split_med_b(t_stack **s_a, t_stack **s_b, t_vals *val, int len)
{
	t_stack	*stack_b;
	int		med;
	int		i;

	i = 0;
	stack_b = *s_b;
	ft_printstacks(*s_a, *s_b);
	ft_printf("split_b: len = %d\n", len);
	if (ft_basic_case(&stack_b,  val, len) == 1)
	{
		ft_printstacks(*s_a, *s_b);
		while (--len)
		{
			ft_push(&stack_b, s_a, val, "pa\n");
			ft_rotate(s_a, val, "ra\n");
		}
		return (1);
	}
	med = ft_get_mediana(stack_b, len);
	while (i < len / 2)
	{
		if (stack_b && stack_b->num >= med)
		{
			ft_push(&stack_b, s_a, val, "pa\n");
			++i;
		}
		else
			ft_rotate(&stack_b, val, "rb\n");
	}
	*s_b = stack_b;
	val->len /= 2;
	ft_split_med_a(s_a, s_b, val, val->len);
	ft_split_med_b(s_a, s_b, val, val->len);
	return (0);
}

int			ft_basic_case(t_stack **s_a, t_vals *val, int len)
{
	t_stack	*a;

	a = *s_a;
	if (len == 1)
		return (1);
	else if (len == 2)
	{
		if (a->num > a->next->num)
			ft_swap(a, val, "sa\n");
		return (1);
	}
	else if (len == 3)
	{
		if (a->num > a->next->num && a->next->num < a->next->next->num)
			ft_swap(a, val, "sa\n");
		else if (a->num > a->next->num && a->next->num > a->next->next->num)
		{
			ft_rotate(&a, val, "ra\n");
			ft_swap(a, val, "sa\n");
			ft_rev_rotate(&a, val, "rra\n");
		}
		else if (a->num > a->next->next->num &&
				a->next->num > a->next->next->num)
		{
			if (a->num < a->next->num)
				ft_swap(a, val, "sa\n");
			ft_rotate(&a, val, "ra\n");
			ft_swap(a, val, "sa\n");
			ft_rev_rotate(&a, val, "rra\n");
			ft_swap(a, val, "sa\n");
		}
		else if (a->num > a->next->num && a->next->num < a->next->next->num)
		{
			ft_swap(a, val, "sa\n");
			ft_rotate(&a, val, "ra\n");
			ft_swap(a, val, "sa\n");
			ft_rev_rotate(&a, val, "rra\n");
		}
	}
	*s_a = a;
	return (0);
}
