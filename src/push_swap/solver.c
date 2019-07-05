/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 00:07:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_quick_sort_a(t_ps *stacks, int len);
int			ft_quick_sort_b(t_ps *stacks, int len);
void		ft_go_to_places(t_ps *stacks, char  cur, int len);
int			ft_check_more_med(t_ps *stacks, char cur, int len);

void		ft_solver(t_stack **stack_a)
{
	t_ps	*stacks;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(MALLOC_FAILURE);
	stacks->a = *stack_a;
	stacks->b = NULL;
	if (!(stacks->line = ft_strnew(0)))
		ft_exit(MALLOC_FAILURE);
	if (!ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)))
		ft_quick_sort_a(stacks, ft_get_length_stack(stacks->a));
	ft_post_processing(stacks);
	ft_printf("%s", stacks->line);
	*stack_a = stacks->a;
//	if (ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)))
//		ft_printf("OK\n");
//	else
//		ft_printf("KO\n");
}

int			ft_quick_sort_a(t_ps *stacks, int len)
{
	int	i;
	int	half;

	if (len <= 3)
		return (ft_basic_case(stacks, 'a', len));
	half = 0;
	stacks->med = ft_get_mediana(stacks->a, len);
	i = len;
	while (i--)
	{
		if (stacks->a->num <= stacks->med)
		{
			ft_push(stacks, 'b');
			++half;
		}
		else
			ft_rotate(stacks, 'a');
	}
	ft_go_to_places(stacks, 'a', len - half);
	ft_quick_sort_b(stacks, half);
	ft_quick_sort_a(stacks, len - half);
	return (0);
}

int			ft_quick_sort_b(t_ps *stacks, int len)
{
	int	half;
	int	i;
	
	if (len >= 0 && len <= 3)
		return (ft_basic_case(stacks, 'b', len));
	half = 0;
	stacks->med = ft_get_mediana(stacks->b, len);
	i = len;
	while (i--)
	{
		if (stacks->b->num >= stacks->med)
		{
			ft_push(stacks, 'a');
			stacks->a->num == stacks->med ? ft_rotate(stacks, 'a') : 0;
			++half;
		}
		else
			ft_rotate(stacks, 'b');
	}
	ft_rev_rotate(stacks, 'a');
	ft_quick_sort_b(stacks, len - half);
	ft_rotate(stacks, 'a');
	ft_quick_sort_a(stacks, half - 1);
	return (0);
}

void		ft_go_to_places(t_ps *stacks, char  cur, int len)
{	
	if (ft_get_length_stack(cur == 'a' ? stacks->a : stacks->b) != len)
	{
		while (len--)
			ft_rev_rotate(stacks, cur);
	}
}

int			ft_check_more_med(t_ps *stacks, char cur, int len)
{
	t_stack	*temp;
	int		i;
	int		last;

	temp = cur == 'a' ? stacks->a : stacks->b;
	i = 0;
	last = 0;
	while (i < len)
	{
		++i;
		if (temp->num <= stacks->med)
			last = i;		
		temp = temp->next;
	}
	return (last);
}
