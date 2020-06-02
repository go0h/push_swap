/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:06:09 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:12:18 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_next_max(t_ps *stacks, char cur, int n)
{
	t_list *first;
	t_list *second;
	int		count;
	int		next_max;

	ft_min_max(stacks, cur);
	first = cur == 'a' ? stacks->a : stacks->b;
	while (first)
	{
		count = 0;
		next_max = NUM(first);
		second = cur == 'a' ? stacks->a : stacks->b;
		while (second)
		{
			count += next_max < NUM(second);
			second = second->next;
		}
		first = first->next;
		if (count == n)
			break ;
	}
	return (next_max);
}

static int	ft_count_to_max(t_ps *stacks, char cur)
{
	t_list *temp;
	int		i;
	int		len;

	ft_min_max(stacks, cur);
	temp = cur == 'a' ? stacks->a : stacks->b;
	len = ft_get_length_stack(temp);
	i = 0;
	while (temp)
	{
		if (NUM(temp) == stacks->max)
			break ;
		temp = temp->next;
		++i;
	}
	return (len - i > i ? 1 : -1);
}

static int	ft_keep_three(t_ps *stacks)
{
	int		len;
	int		three;

	three = ft_get_next_max(stacks, 'a', 2);
	len = ft_get_length_stack(stacks->a);
	while (len > 3)
	{
		stacks->med = ft_get_mediana(stacks->a, len, 0);
		while (len--)
		{
			if (NUM(stacks->a) <= stacks->med && NUM(stacks->a) < three)
			{
				ft_push(stacks, 'b');
				ft_abs(NUM(stacks->b)) <= ft_abs(stacks->med) / 2 ?
					ft_rotate(stacks, 'b') : 0;
			}
			else
				ft_rotate(stacks, 'a');
		}
		len = ft_get_length_stack(stacks->a);
	}
	ft_sort_three(stacks, 'a');
	return (0);
}

void		ft_select_sort(t_ps *stacks)
{
	int i;
	int j;
	int	next_max;

	j = ft_keep_three(stacks);
	while (stacks->b)
	{
		i = ft_count_to_max(stacks, 'b');
		next_max = ft_get_next_max(stacks, 'b', 1);
		while (stacks->b && NUM(stacks->b) != stacks->max)
		{
			if (NUM(stacks->b) == stacks->min || NUM(stacks->b) == next_max)
			{
				ft_push(stacks, 'a');
				j += NUM(stacks->a) == stacks->min ? ft_rotate(stacks, 'a') : 0;
			}
			else
				i < 0 ? ft_rev_rotate(stacks, 'b') : ft_rotate(stacks, 'b');
		}
		ft_push(stacks, 'a');
		NUM(stacks->a) > NUM(stacks->a->next) ? ft_swap(stacks, 'a') : 0;
	}
	while (j--)
		ft_rev_rotate(stacks, 'a');
}

int			ft_min_max(t_ps *stacks, char cur)
{
	t_list *temp;

	temp = cur == 'a' ? stacks->a : stacks->b;
	temp ? stacks->max = NUM(temp) : 0;
	temp ? stacks->min = NUM(temp) : 0;
	while (temp)
	{
		if (NUM(temp) > stacks->max)
			stacks->max = NUM(temp);
		if (NUM(temp) < stacks->min)
			stacks->min = NUM(temp);
		temp = temp->next;
	}
	return (1);
}
