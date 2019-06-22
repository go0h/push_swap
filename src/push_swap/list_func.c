/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:27:55 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 17:40:37 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_newlist(int num)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		exit(MALLOC_FAILURE);
	new->num = num;
	new->next = NULL;
	return (new);
}

void		ft_addnew(t_stack **begin, int num)
{
	t_stack *temp;
	t_stack *new;

	if (*begin)
	{
		temp = *begin;
		new = ft_newlist(num);
		new->next = temp;
	}
	else
		new = ft_newlist(num);
	*begin = new;
}

void		ft_delstack(t_stack **begin)
{
	t_stack *temp;
	t_stack *next;

	if (begin)
	{
		temp = *begin;
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*begin = NULL;
	}
}

void		ft_printstack(t_stack *begin)
{
	while (begin)
	{
		ft_printf("%d\n", begin->num);
		begin = begin->next;
	}
}

void		ft_printstacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("-----------------\n");
	ft_printf("|   a   |   b   |\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("|%7d|%7d|\n", stack_a->num, stack_b->num);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && !stack_b)
		{
			ft_printf("|%7d|       |\n", stack_a->num);
			stack_a = stack_a->next;
		}
		else if (!stack_a && stack_b)
		{
			ft_printf("|       |%7d|\n", stack_b->num);
			stack_b = stack_b->next;
		}
	}
	ft_printf("-----------------\n");
}

void		ft_delonelist(t_stack **begin)
{
	t_stack *temp;

	temp = *begin;
	if (temp)
	{
		temp = temp->next;
		free(*begin);
		*begin = temp;
	}
}
