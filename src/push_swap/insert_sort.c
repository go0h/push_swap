/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:40:15 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/10 22:11:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_keep_three(t_ps *stacks);
int			ft_min_max(t_ps *stacks, char cur);
int			ft_count_to_max(t_ps *stacks, char cur);
int			ft_get_next_max(t_ps *stacks, char cur);

int			ft_insert_sort(t_ps *stacks, int len)
{
	int i;
	int j;
	int	next_max;
	
	j = ft_keep_three(stacks);
	while (--len)
	{
		i = ft_count_to_max(stacks, 'b');
		next_max = ft_get_next_max(stacks, 'b');
		while (stacks->count > 0)
		{
			if (stacks->b->num == stacks->min || stacks->b->num == next_max)
			{
				ft_push(stacks, 'a');
				j += stacks->a->num == stacks->min ? ft_rotate(stacks, 'a') : 0;
				i = ft_count_to_max(stacks, 'b');
				++stacks->count;
			}
			else
				i < 0 ? ft_rev_rotate(stacks, 'b') : ft_rotate(stacks, 'b');
			stacks->count--;
		}
		ft_push(stacks, 'a');
		stacks->a->num > stacks->a->next->num ? ft_swap(stacks, 'a') : 0;
	}
	while (j--)
		ft_rev_rotate(stacks, 'a');
	return (1);
}

int		ft_keep_three(t_ps *stacks)
{
	int		len;

	len = ft_get_length_stack(stacks->a);
	while (len > 3)
	{
		stacks->med = ft_get_mediana(stacks->a, len);
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
	ft_basic_case(stacks, 'a', len);
	return (0);
}

int		ft_get_next_max(t_ps *stacks, char cur)
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

int		ft_min_max(t_ps *stacks, char cur)
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

int		ft_count_to_max(t_ps *stacks, char cur)
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
