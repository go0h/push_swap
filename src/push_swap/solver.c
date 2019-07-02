/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/03 00:40:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_sort(t_ps *stacks, char cur_s, int len);

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
//	ft_printf("%s", stacks->line);
	ft_printstacks(stacks->a, stacks->b);
	*stack_a = stacks->a;
}

int			ft_quick_sort(t_ps *stacks, char cur, int len)
{
	int	med;
	int	half;
	int	i;
	
	if (len >= 0 && len <= 3)
		return (ft_basic_case(stacks, cur, len));
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
	ft_quick_sort(stacks, cur, len - half);
	ft_quick_sort(stacks, cur == 'a' ? 'b' : 'a', half);
	return (0);
}
