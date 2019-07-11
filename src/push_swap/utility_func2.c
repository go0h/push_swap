/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:47:04 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 18:51:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_init_stacks(int ac, char **av)
{
	t_ps	*stacks;
	int		len;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(NULL, MALLOC_FAILURE);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->i = 0;
	stacks->line = NULL;
	stacks->count = 0;
	while (ac >= 0)
		ft_addnew(&stacks->a, ft_myatoi(av[ac--], stacks));
	ft_find_dup(stacks->a);
	len = ft_get_length_stack(stacks->a);
	if (!(stacks->line = ft_strnew(len * len)))
		ft_exit(&stacks, MALLOC_FAILURE);
	return (stacks);
}

void	ft_free_stacks(t_ps **to_del)
{
	t_ps *stacks;

	if (to_del)
	{
		stacks = *to_del;
		ft_delstack(&stacks->a);
		ft_delstack(&stacks->b);
		ft_strdel(&stacks->line);
		free(stacks);
		to_del = NULL;
	}
}

int		ft_get_length_stack(t_stack *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

int		ft_len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}
