/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:19:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 19:45:19 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_operation(t_ps *stacks, char *oper)
{
	if (!(ft_strcmp("sa", oper)))
		ft_swap(stacks, 'a');
	else if (!(ft_strcmp("sb", oper)))
		ft_swap(stacks, 'b');
	else if (!(ft_strcmp("ss", oper)))
		ft_swap_two(stacks);
	else if (!(ft_strcmp("pa", oper)))
		ft_push(stacks, 'a');
	else if (!(ft_strcmp("pb", oper)))
		ft_push(stacks, 'b');
	else if (!(ft_strcmp("ra", oper)))
		ft_rotate(stacks, 'a');
	else if (!(ft_strcmp("rb", oper)))
		ft_rotate(stacks, 'b');
	else if (!(ft_strcmp("rra", oper)))
		ft_rev_rotate(stacks, 'a');
	else if (!(ft_strcmp("rrb", oper)))
		ft_rev_rotate(stacks, 'b');
	else if (!(ft_strcmp("rrr", oper)))
		ft_rev_rotate_two(stacks);
	else if (!(ft_strcmp("rr", oper)))
		ft_rotate_two(stacks);
	else
		ft_exit(&stacks, WRONG_OPERATION);
	return (1);
}
