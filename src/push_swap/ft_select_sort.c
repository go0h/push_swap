/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:06:09 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/12 22:05:51 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_next_max(t_ps *stacks, char cur)
{
	t_stack *first;
	t_stack *second;
	int		count;
	int		next_max;

	first = cur == 'a' ? stacks->a : stacks->b;
	while (first)
	{
		count = 0;
		next_max = first->num;
		second = cur == 'a' ? stacks->a : stacks->b;
		while (second)
		{
			count += next_max < second->num;
			second = second->next;
		}
		first = first->next;
		if (count == 1)
			break ;
	}
	return (next_max);
}

static int	ft_count_to_max(t_ps *stacks, char cur)
{
	t_stack *temp;
	int		i;
	int		len;

	ft_min_max(stacks, cur);
	temp = cur == 'a' ? stacks->a : stacks->b;
	len = ft_get_length_stack(temp);
	i = 0;
	while (temp)
	{
		if (temp->num == stacks->max)
		{
			stacks->count = ft_abs(ft_min(len - i, i));
			break ;
		}
		temp = temp->next;
		++i;
	}
	return (len - i >= i ? 1 : -1);
}

static int	ft_keep_three(t_ps *stacks)
{
	int		len;

	len = ft_get_length_stack(stacks->a);
	while (len > 3)
	{
		stacks->med = ft_get_mediana(stacks->a, len, 0);
		while (len--)
		{
			if (stacks->a->num <= stacks->med)
			{
				ft_push(stacks, 'b');
				stacks->b->num <= stacks->med / 2 ? ft_rotate(stacks, 'b') : 0;
			}
			else
				ft_rotate(stacks, 'a');
		}
		len = ft_get_length_stack(stacks->a);
	}
	len == 3 ? ft_sort_three(stacks, 'a') : 0;
	if (len == 2 && stacks->a->num > stacks->a->next->num)
		ft_swap(stacks, 'a');
	return (0);
}

void		ft_select_sort(t_ps *stacks, int len)
{
	int i;
	int j;
	int	next_max;

	j = ft_keep_three(stacks);
	while (--len)
	{
		i = ft_count_to_max(stacks, 'b');
		next_max = ft_get_next_max(stacks, 'b');
		while (stacks->count-- > 0)
		{
			if (stacks->b->num == stacks->min || stacks->b->num == next_max)
			{
				ft_push(stacks, 'a');
				j += stacks->a->num == stacks->min ? ft_rotate(stacks, 'a') : 0;
				i < 0 ? stacks->count++ : 0;
			}
			else
				i < 0 ? ft_rev_rotate(stacks, 'b') : ft_rotate(stacks, 'b');
		}
		ft_push(stacks, 'a');
		stacks->a->num > stacks->a->next->num ? ft_swap(stacks, 'a') : 0;
	}
	while (j--)
		ft_rev_rotate(stacks, 'a');
}

int			ft_min_max(t_ps *stacks, char cur)
{
	t_stack *temp;

	temp = cur == 'a' ? stacks->a : stacks->b;
	temp ? stacks->max = temp->num : 0;
	temp ? stacks->min = temp->num : 0;
	while (temp)
	{
		if (temp->num > stacks->max)
			stacks->max = temp->num;
		if (temp->num < stacks->min)
			stacks->min = temp->num;
		temp = temp->next;
	}
	return (1);
}
