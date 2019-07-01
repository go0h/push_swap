/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/02 01:16:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_sort(t_ps *stacks, char cur_s, int len);

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
	ft_quick_sort(stacks, 'a', ft_get_length_stack(stacks->a));
	ft_printstacks(stacks->a, stacks->b);
}

int			ft_quick_sort(t_ps *stacks, char cur, int len)
{
	int	med;
	int	half;
	int	i;
	t_stack	*temp;

	temp = cur == 'a' ? stacks->a : stacks->b;	
	if (ft_basic_case(stacks, cur, len) == 1)
		return (1);
	half = 0;
	med = ft_get_mediana(temp, len);
	i = 0;
	while (i < len)
	{
		if (temp->num >= med)
		{
			ft_push(stacks, cur == 'a' ? 'b' : cur);
			++half;
		}
		else
			ft_rotate(stacks, cur);
		++i;
		ft_printstacks(stacks->a, stacks->b);
	}
	ft_quick_sort(stacks, 'b', half);
	ft_quick_sort(stacks, 'a', len - half);
	return (0);
}

int			ft_basic_case(t_ps *stacks, char cur, int len)
{
	t_stack	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (len == 1)
	{
//		ft_printf("len = %d\n", len);
		return (1);
	}
	else if (len == 2)
	{
//		ft_printf("len = %d\n", len);
		if (a->num > a->next->num)
			ft_swap(stacks, cur);
		return (1);
	}
	else if (len == 3)
	{
//		ft_printf("len = %d\n", len);
		if (a->num > a->next->num && a->next->num < a->next->next->num)
			ft_swap(stacks, cur);
		else if (a->num > a->next->num && a->next->num > a->next->next->num)
		{
			ft_rotate(stacks, cur);
			ft_swap(stacks, cur);
			ft_rev_rotate(stacks, cur);
		}
		else if (a->num > a->next->next->num &&
				a->next->num > a->next->next->num)
		{
			if (a->num < a->next->num)
				ft_swap(stacks, cur);
			ft_rotate(stacks, cur);
			ft_swap(stacks, cur);
			ft_rev_rotate(stacks, cur);
			ft_swap(stacks, cur);
		}
		else if (a->num > a->next->num && a->next->num < a->next->next->num)
		{
			ft_swap(stacks, cur);
			ft_rotate(stacks, cur);
			ft_swap(stacks, cur);
			ft_rev_rotate(stacks, cur);
		}
		return (1);
	}
	if (cur == 'a')
		stacks->a = a;
	else
		stacks->b = a;
	return (0);
}
