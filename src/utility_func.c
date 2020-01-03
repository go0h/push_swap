/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:37:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 21:40:43 by astripeb         ###   ########.fr       */
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

void		ft_find_dup(t_stack *stack)
{
	int		n;
	int		count;
	t_stack *first;
	t_stack	*second;

	first = stack;
	while (first)
	{
		count = 0;
		n = first->num;
		second = stack;
		while (second)
		{
			if (n == second->num)
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

int			ft_get_mediana(t_stack *begin, int len, int flag)
{
	t_stack	*first;
	t_stack	*second;
	int		temp_len;
	int		count;
	int		med;

	first = begin;
	while (first)
	{
		count = 0;
		temp_len = len;
		med = first->num;
		second = begin;
		while (second && temp_len--)
		{
			if (med > second->num)
				++count;
			second = second->next;
		}
		if (count == len / 2 + flag)
			break ;
		first = first->next;
	}
	return (med);
}

int			ft_check_sort(t_stack *stack_a, int len, int flag)
{
	int n;
	int i;

	i = 0;
	n = stack_a->num;
	stack_a = stack_a->next;
	while (stack_a && i < len)
	{
		if (n >= stack_a->num && !flag)
			return (0);
		if (n <= stack_a->num && flag)
			return (0);
		n = stack_a->num;
		stack_a = stack_a->next;
		++i;
	}
	return (1);
}
