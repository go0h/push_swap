/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:40:15 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 17:47:01 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_keep_three(t_ps *stacks);
int			ft_min_max(t_ps *stacks, char cur);
int			ft_count_to_max(t_ps *stacks, char cur);

int			ft_insert_sort(t_ps *stacks, int len)
{
	int i;
	int j;

	j = 0;
	ft_keep_three(stacks);
	while (len > 1)
	{
		ft_min_max(stacks, 'b');
		i = ft_count_to_max(stacks, 'b');
		while (stacks->count > 0)
		{
			if (stacks->b->num == stacks->min)
			{
				ft_push(stacks, 'a');
				j += ft_rotate(stacks, 'a');
				i < 0 ? stacks->count += 1 : 0;
			}
			else
				i < 0 ? ft_rev_rotate(stacks, 'b') : ft_rotate(stacks, 'b');
			stacks->count--;
		}
		ft_push(stacks, 'a');
		stacks->a->num > stacks->a->next->num ? ft_swap(stacks, 'a') : 0;
		--len;
	}
	while (j--)
		ft_rev_rotate(stacks, 'a');
	return (1);
}

void		ft_keep_three(t_ps *stacks)
{
	int		len;
	
	len = ft_get_length_stack(stacks->a);
	while (len > 3)
	{
		stacks->med = ft_get_mediana(stacks->a, len);
		while (len--)
		{
			if (stacks->a->num <= stacks->med)
				ft_push(stacks, 'b');
			else
				ft_rotate(stacks, 'a');
		}
		len = ft_get_length_stack(stacks->a);
	}
	ft_sort_three(stacks, 'a');
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
