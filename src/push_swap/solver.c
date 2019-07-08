/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:52 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 17:47:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_solver(t_stack **stack_a)
{
	t_ps	*stacks;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(NULL, MALLOC_FAILURE);
	stacks->a = *stack_a;
	stacks->b = NULL;
	if (!(stacks->line = ft_strnew(0)))
		ft_exit(&stacks, MALLOC_FAILURE);
	if (!ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)))
	{
		if (ft_get_length_stack(stacks->a) <= 100)
			ft_insert_sort(stacks, ft_get_length_stack(stacks->a));
		else
			ft_sort_a(stacks, ft_get_length_stack(stacks->a));
	}
//	ft_post_processing(stacks);
	ft_printf("%s", stacks->line);
//	ft_printstacks(stacks->a, stacks->b);
/*	if (ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
*/	ft_free_stacks(&stacks);

}

int			ft_sort_a(t_ps *stacks, int len)
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
			half += ft_push(stacks, 'b');
		else
			ft_rotate(stacks, 'a');
	}
	if (ft_get_length_stack(stacks->a) != len - half)
	{
		i = len - half;
		while (i--)
			ft_rev_rotate(stacks, 'a');
	}
	ft_sort_b(stacks, half);
	ft_sort_a(stacks, len - half);
	return (0);
}

int			ft_sort_b(t_ps *stacks, int len)
{
	int	half;
	int	i;
	int	flag;

	if (len >= 0 && len <= 3)
		return (ft_basic_case(stacks, 'b', len));
	half = 0;
	flag = 0;
	stacks->med = ft_get_mediana(stacks->b, len);
	i = len;
	while (i--)
	{
		if (stacks->b->num >= stacks->med)
		{
			half += ft_push(stacks, 'a');
			stacks->a->num == stacks->med ? flag = ft_rotate(stacks, 'a') : 0;
		}
		else
			ft_rotate(stacks, 'b');
	}
	flag ? ft_rev_rotate(stacks, 'a') : 0;
	ft_sort_b(stacks, len - half);
	flag ? ft_rotate(stacks, 'a') : 0;
	ft_sort_a(stacks, half - flag);
	return (0);
}
