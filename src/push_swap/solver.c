/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/02 00:05:35 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_sort(t_ps *stacks, char cur_s, int len);

void		ft_solver(t_stack *stack_a)
{
	t_ps	*stacks;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(MALLOC_FAILURE);
	stacks->a = stack_a;
	stacks->b = NULL;
	if (!(stacks->line = ft_strnew(0)))
		ft_exit(MALLOC_FAILURE);
	stacks->cur = 'a';
	ft_quick_sort(t_ps *stacks, 'a', ft_get_length_stack(stacks->a));
	ft_printstacks(stacks->a, stacks->b);
}

int			ft_quick_sort(t_ps *stacks, char cur_s, int len)
{
	int	med;
	int	half;
	int	i;
	t_stack	*cur;

	
	if (ft_basic_case(cur_s == 'a' ? stacks->a : stacks->b, len) == 1)
		return (1);
	half = 0;
	med = ft_get_mediana(*s_a, len);
	i = 0;
	while (i < len)
	{
		if ((*s_a)->num > med)
		{
			ft_push(s_a, s_b, val, "pb\n");
			++half;
		}
		else
			ft_rotate(s_a, val, "ra\n");
		++i;
	}
	ft_printstacks(*s_a, *s_b);
//	ft_printf("len = %d, half = %d\n", len, half);
	ft_quick_sort(s_b, s_a, val, half);
	ft_quick_sort(s_a, s_b, val, len - half);
	return (0);
}

int			ft_basic_case(t_stack **s_a, t_vals *val, int len)
{
	t_stack	*a;

	a = *s_a;
	if (len == 1)
	{
//		ft_printf("len = %d\n", len);
		return (1);
	}
	else if (len == 2)
	{
//		ft_printf("len = %d\n", len);
		if (a->num > a->next->num)
			ft_swap(a, val, "sa\n");
		return (1);
	}
	else if (len == 3)
	{
//		ft_printf("len = %d\n", len);
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
