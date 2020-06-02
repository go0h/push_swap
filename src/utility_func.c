/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:37:31 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:23:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_arg(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < ac && av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			++j;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || j > 11)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void		ft_find_dup(t_list *stack)
{
	int		n;
	int		count;
	t_list	*first;
	t_list	*second;

	first = stack;
	while (first)
	{
		count = 0;
		n = NUM(first);
		second = stack;
		while (second)
		{
			if (n == NUM(second))
				++count;
			second = second->next;
		}
		if (count > 1)
			ft_exit(NULL, WRONG_INPUT);
		first = first->next;
	}
}

int			ft_myatoi(char *str, t_ps *stacks)
{
	int		n;
	char	*check;

	n = ft_atoi(str);
	if (!(check = ft_itoa(n)))
		ft_exit(&stacks, MALLOC_FAILURE);
	if (ft_strcmp(str, check))
		ft_exit(&stacks, WRONG_INPUT);
	ft_strdel(&check);
	return (n);
}

int			ft_get_mediana(t_list *begin, int len, int flag)
{
	t_list	*first;
	t_list	*second;
	int		temp_len;
	int		count;
	int		med;

	first = begin;
	while (first)
	{
		count = 0;
		temp_len = len;
		med = NUM(first);
		second = begin;
		while (second && temp_len--)
		{
			if (med > NUM(second))
				++count;
			second = second->next;
		}
		if (count == len / 2 + flag)
			break ;
		first = first->next;
	}
	return (med);
}

int			ft_check_sort(t_list *stack_a, int len, int flag)
{
	int n;
	int i;

	i = 0;
	n = NUM(stack_a);
	stack_a = stack_a->next;
	while (stack_a && i < len)
	{
		if (n >= NUM(stack_a) && !flag)
			return (0);
		if (n <= NUM(stack_a) && flag)
			return (0);
		n = NUM(stack_a);
		stack_a = stack_a->next;
		++i;
	}
	return (1);
}
