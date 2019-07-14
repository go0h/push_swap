/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/14 11:29:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_solver(int ac, char **av)
{
	t_ps	*stacks;
	int		len;

	stacks = ft_init_stacks(ac, av);
	len = ft_get_length_stack(stacks->a);
	if (!ft_check_sort(stacks->a, len, 0))
	{
		if (len < 6)
			ft_case_six(stacks, 'a', len);
		else if (len < 101)
			ft_select_sort(stacks, len);
		else
			ft_sort_a(stacks, len);
	}
	ft_post_processing(stacks);
	ft_free_stacks(&stacks);
}

int			ft_sort_a(t_ps *stacks, int len)
{
	int	i;
	int	half;

	if (len <= 3)
		return (ft_basic_case(stacks, 'a', len));
	half = 0;
	stacks->med = ft_get_mediana(stacks->a, len, 1);
	i = len;
	ft_min_max(stacks, 'a');
	while (i--)
	{
		if (stacks->a->num <= stacks->med)
			half += ft_push(stacks, 'b');
		else
			ft_rotate(stacks, 'a');
	}
	if (ft_get_length_stack(stacks->a) != len - half)
		while (i < len - half - 1)
			i += ft_rev_rotate(stacks, 'a');
	ft_sort_b(stacks, half);
	ft_sort_a(stacks, len - half);
	return (0);
}

int			ft_sort_b(t_ps *stacks, int len)
{
	int	half;
	int	i;

	if (len >= 0 && len <= 3)
		return (ft_basic_case(stacks, 'b', len));
	half = 0;
	stacks->med = ft_get_mediana(stacks->b, len, 1);
	i = len;
	ft_min_max(stacks, 'b');
	while (i--)
	{
		if (stacks->b->num >= stacks->med)
			half += ft_push(stacks, 'a');
		else if (stacks->b->num == stacks->min)
		{
			len -= ft_push(stacks, 'a');
			ft_rotate(stacks, 'a');
			ft_min_max(stacks, 'b');
		}
		else
			ft_rotate(stacks, 'b');
	}
	ft_sort_b(stacks, len - half);
	ft_sort_a(stacks, half);
	return (0);
}
