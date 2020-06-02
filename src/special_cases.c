/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:22:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_three_on_stack(t_ps *stacks, char cur)
{
	t_list	*a;
	int		flag;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (NUM(a) < NUM(a->next) && NUM(a->next) < NUM(a->next->next))
		return (1);
	if (NUM(a) < NUM(a->next))
	{
		flag = (NUM(a) > NUM(a->next->next));
		ft_rotate(stacks, cur);
		ft_swap(stacks, cur);
		ft_rev_rotate(stacks, cur);
		flag > 0 ? ft_swap(stacks, cur) : 0;
	}
	else if (NUM(a) > NUM(a->next))
	{
		flag = (NUM(a->next) > NUM(a->next->next));
		flag += (NUM(a) > NUM(a->next->next));
		ft_swap(stacks, cur);
		flag > 0 ? ft_rotate(stacks, cur) : 0;
		flag > 0 ? ft_swap(stacks, cur) : 0;
		flag > 0 ? ft_rev_rotate(stacks, cur) : 0;
		flag > 1 ? ft_swap(stacks, cur) : 0;
	}
	return (1);
}

int			ft_sort_three(t_ps *stacks, char cur)
{
	t_list	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (ft_check_sort(a, 3, 0) == 1)
		return (1);
	else if (NUM(a) > NUM(a->next) && NUM(a) < NUM(a->next->next))
		ft_swap(stacks, cur);
	else if (NUM(a) < NUM(a->next) && NUM(a) < NUM(a->next->next))
	{
		ft_rev_rotate(stacks, cur);
		ft_swap(stacks, cur);
	}
	else if (NUM(a) < NUM(a->next) && NUM(a) > NUM(a->next->next))
		ft_rev_rotate(stacks, cur);
	else if (NUM(a) > NUM(a->next) && NUM(a->next) < NUM(a->next->next))
		ft_rotate(stacks, cur);
	else if (NUM(a) > NUM(a->next) && NUM(a->next) > NUM(a->next->next))
	{
		ft_swap(stacks, cur);
		ft_rev_rotate(stacks, cur);
	}
	return (1);
}

int			ft_basic_case(t_ps *stacks, char cur, int len)
{
	t_list	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (len == 2 && NUM(a) > NUM(a->next))
		ft_swap(stacks, cur);
	else if (len == 3)
		ft_get_length_stack(a) == 3 ? ft_sort_three(stacks, cur) :\
		ft_sort_three_on_stack(stacks, cur);
	while (len--)
	{
		cur == 'b' ? ft_push(stacks, 'a') : 0;
		ft_rotate(stacks, 'a');
	}
	return (1);
}

static int	ft_sort_rev_three(t_ps *stacks, char cur)
{
	t_list	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (ft_check_sort(a, 3, 1) == 1)
		return (1);
	else if (ft_check_sort(a, 3, 0) == 1)
	{
		ft_swap(stacks, cur);
		ft_rev_rotate(stacks, cur);
	}
	else if (NUM(a) < NUM(a->next) && NUM(a) < NUM(a->next->next))
		ft_rotate(stacks, cur);
	else if (NUM(a) > NUM(a->next) && NUM(a) < NUM(a->next->next))
		ft_rev_rotate(stacks, cur);
	else if (NUM(a) < NUM(a->next) && NUM(a) > NUM(a->next->next))
		ft_swap(stacks, cur);
	else if (NUM(a) > NUM(a->next) && NUM(a) > NUM(a->next->next))
	{
		ft_rev_rotate(stacks, cur);
		ft_swap(stacks, cur);
	}
	return (1);
}

int			ft_case_six(t_ps *stacks, char cur, int l)
{
	int		h;

	if (l == 1)
		return (1);
	else if (l == 2 && NUM(stacks->a) > NUM(stacks->a->next))
		return (ft_swap(stacks, cur));
	else if (l == 3)
		return (ft_sort_three(stacks, cur));
	h = 0;
	stacks->med = ft_get_mediana(stacks->a, l, 0);
	while (l--)
	{
		if (NUM(stacks->a) <= stacks->med)
			h += ft_push(stacks, cur == 'a' ? 'b' : 'a');
		else
			ft_rotate(stacks, cur);
	}
	l = ft_get_length_stack(stacks->a);
	l == 3 ? ft_sort_three(stacks, 'a') : 0;
	l == 2 && NUM(stacks->a) > NUM(stacks->a->next) ? ft_swap(stacks, 'a') : 0;
	h == 3 ? ft_sort_rev_three(stacks, 'b') : 0;
	h == 2 && NUM(stacks->b) < NUM(stacks->b->next) ? ft_swap(stacks, 'b') : 0;
	while (h--)
		ft_push(stacks, cur);
	return (1);
}
