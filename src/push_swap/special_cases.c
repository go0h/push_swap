/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/02 23:07:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_basic_case(t_ps *stacks, char cur, int len)
{
	t_stack	*a;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (len == 2 && a->num > a->next->num)
		ft_swap(stacks, cur);
	else if (len == 3)
		ft_sort_three(stacks, cur);
	if ((!ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)) && !stacks->b)
			|| stacks->b)
	{
		while (len--)
		{
			cur == 'b' ? ft_push(stacks, 'a') : 0;
			ft_rotate(stacks, 'a');
		}
		return (0);
	}
	return (1);
}

int		ft_sort_three(t_ps *stacks, char cur)
{
	t_stack	*a;
	int		flag;

	a = cur == 'a' ? stacks->a : stacks->b;
	if (a->num < a->next->num && a->next->num < a->next->next->num)
		return (1);
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
	return (1);
}
