/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/02 22:31:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_sort(t_ps *stacks, char cur_s, int len);
int		ft_sort_three(t_ps *stacks, char cur);

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
}

int			ft_quick_sort(t_ps *stacks, char cur, int len)
{
	int	med;
	int	half;
	int	i;
	
	if (ft_basic_case(stacks, cur, len) == 1)
		return (1);
	half = 0;
	med = ft_get_mediana(cur == 'a' ? stacks->a : stacks->b, len);
	i = 0;
	while (i < len)
	{
		if ((cur == 'a' ? stacks->a->num : stacks->b->num) >= med)
		{
			ft_push(stacks, cur == 'a' ? 'b' : 'a');
			++half;
		}
		else
			ft_rotate(stacks, cur);
		++i;
	}
	ft_quick_sort(stacks, cur == 'a' ? 'b' : 'a', half);
	ft_quick_sort(stacks, cur, len - half);
	return (0);
}

int			ft_basic_case(t_ps *stacks, char cur, int len)
{
	t_stack	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (len == 1)
		return (1);
	else if (len == 2)
	{
		if (a->num > a->next->num)
			ft_swap(stacks, cur);
		return (1);
	}
	else if (len == 3)
	{
		ft_sort_three(stacks, cur);
		return (1);
	}
	if (cur == 'a')
		stacks->a = a;
	else
		stacks->b = a;
	return (0);
}
		
int		ft_sort_three(t_ps *stacks, char cur)
{
	t_stack	*a;
	int		flag;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (a->num < a->next->num)
	{
		flag = (a->num > a->next->next->num);
		ft_rotate(stacks, cur);
		ft_swap(stacks, cur);
		ft_rev_rotate(stacks, cur);
		flag > 0 ? ft_swap(stacks, cur) : 0;
	}
	else if (a->num > a->next->num)
	{
		flag = (a->next->num > a->next->next->num);
		flag += (a->num > a->next->next->num);
		ft_swap(stacks, cur);
		flag > 0 ? ft_rotate(stacks, cur) : 0;
		flag > 0 ? ft_swap(stacks, cur) : 0;
		flag > 0 ? ft_rev_rotate(stacks, cur) : 0;
		flag > 1 ? ft_swap(stacks, cur) : 0;
	}
	stacks->a = (cur == 'a') ? a : stacks->a;
	stacks->b = (cur == 'b') ? a : stacks->b;
	return (1);
}
