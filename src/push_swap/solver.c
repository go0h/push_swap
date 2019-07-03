/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/03 00:40:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_quick_sort_a(t_ps *stacks, int len);
int			ft_quick_sort_b(t_ps *stacks, int len);

void		ft_solver(t_stack **stack_a)
{
	t_ps	*stacks;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(MALLOC_FAILURE);
	stacks->a = *stack_a;
	stacks->b = NULL;
	if (!(stacks->line = ft_strnew(0)))
		ft_exit(MALLOC_FAILURE);
	stacks->cur = 'a';
	ft_quick_sort_a(stacks, ft_get_length_stack(stacks->a));
//	ft_printf("%s", stacks->line);
	ft_printstacks(stacks->a, stacks->b);
	*stack_a = stacks->a;
}

int			ft_quick_sort_a(t_ps *stacks, int len)
{
	int	med;
	int	half;
	int	i;
	
	if (len <= 3)
		return (ft_basic_case(stacks, 'a', len));
	med = ft_get_mediana(stacks->a, len);
	half = 0;
	i = 0;
	while (i < len)
	{
		if (stacks->a->num <= med)
		{
			ft_push(stacks, 'b');
			++half;
		}
		else
			ft_rotate(stacks, 'a');
		++i;
	}
	while (i - half)
	{
		ft_rev_rotate(stacks, 'a');
		--i;
	}
	ft_quick_sort_b(stacks, half);
	ft_quick_sort_a(stacks, len - half);
	return (0);
}

int			ft_quick_sort_b(t_ps *stacks, int len)
{
	int	med;
	int	half;
	int	i;
	
	if (len >= 0 && len <= 3)
		return (ft_basic_case(stacks, 'b', len));
	half = 0;
	med = ft_get_mediana(stacks->b, len);
	i = 0;
	while (i < len)
	{
		if (stacks->b->num <= med)
		{
			ft_push(stacks, 'a');
			++half;
		}
		else
			ft_rotate(stacks, 'b');
		++i;
	}
	while (i - half)
	{
		ft_rev_rotate(stacks, 'b');
		--i;
	}
	ft_quick_sort_a(stacks, half);
	ft_quick_sort_b(stacks, len - half);
	return (0);
}