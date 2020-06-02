/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:47:04 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:43:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_init_stacks(int ac, char **av)
{
	t_ps	*stacks;
	t_list	*temp;
	int		len;
	int		n;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(NULL, MALLOC_FAILURE);
	ft_bzero(stacks, sizeof(t_ps));
	while (ac >= 0)
	{
		n = ft_myatoi(av[ac--], stacks);
		temp = ft_lstnew(&n, sizeof(int));
		if (!temp)
			ft_exit(&stacks, MALLOC_FAILURE);
		ft_lstadd(&stacks->a, temp);
	}
	ft_find_dup(stacks->a);
	len = ft_get_length_stack(stacks->a);
	if (!(stacks->line = ft_strnew(len * len)))
		ft_exit(&stacks, MALLOC_FAILURE);
	return (stacks);
}

void	ft_del_content(void * content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}

void	ft_free_stacks(t_ps **to_del)
{
	t_ps *stacks;

	if (to_del)
	{
		stacks = *to_del;
		ft_lstdel(&stacks->a, &ft_del_content);
		ft_lstdel(&stacks->b, &ft_del_content);
		ft_strdel(&stacks->line);
		free(stacks);
		to_del = NULL;
	}
}

int		ft_get_length_stack(t_list *stack)
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
