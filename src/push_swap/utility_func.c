/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:37:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/24 23:25:38 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_arg(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < ac)
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
			ft_exit(WRONG_INPUT);
		first = first->next;
	}
}

int			ft_myatoi(char *str)
{
	int n;
	int	flag;

	while (ft_isspace(*str))
		++str;
	flag = (*str == '+' || *str == '-') ? (44 - *str++) : 1;
	n = 0;
	while (ft_isdigit(*str))
	{
		if (flag == 1 && (n * 10 + (*str - '0')) < 0)
			ft_exit(WRONG_INPUT);
		if (flag == -1 && (n * -10 - (*str - '0')) > 0)
			ft_exit(WRONG_INPUT);
		n = n * 10 + (*str++ - '0');
	}
	return (n * flag);
}

int			ft_get_mediana(int ac, char **av)
{
	int		*arr;
	int		i;

	if (!(arr = ft_memalloc(sizeof(int) * ac)))
		ft_exit(MALLOC_FAILURE);
	i = 0;
	while (i < ac)
	{
		arr[i] = ft_myatoi(av[i]);
		++i;
	}
	if (!(ft_merge_sort(arr, ac)))
		ft_exit(MALLOC_FAILURE);
	if (ac % 2 == 1)
		i = arr[ac / 2];
	else
		i = (arr[ac / 2] + arr[ac / 2 + 1]) / 2;
	free(arr);
	return (i);
}
