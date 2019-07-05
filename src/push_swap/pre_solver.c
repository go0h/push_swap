/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:41:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/05 17:20:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_get_half_stack(t_ps *stacks);

void		ft_pre_solver(t_ps *stacks)
{
	int len;

	len = ft_get_length_stack(stacks->a);
	stacks->med = ft_get_mediana(stacks->a, len);
	while (len--)
	{
		if (stacks->a->num <= stacks->med)
			ft_push(stacks, 'b');
		else
			ft_rotate(stacks, 'a');
	}
	while (ft_get_length_stack(stacks->b) != 0)
		ft_get_half_stack(stacks);
}

void		ft_get_half_stack(t_ps *stacks)
{
	int		len;

	len = ft_get_length_stack(stacks->b);
	stacks->med = ft_get_mediana(stacks->b, len);
	while (len--)
	{
		if (stacks->b->num >= stacks->med)
			ft_push(stacks, 'a');
		else
			ft_rotate(stacks, 'b');
	}
}
