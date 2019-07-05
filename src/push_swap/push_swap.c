/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/05 18:47:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**ar;
	int		i;

	stack_a = NULL;
	ar = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!(ar = ft_strsplit_sp(argv[1])))
			ft_exit(MALLOC_FAILURE);
	}
	else
		ar = &argv[1];
	if (!(ft_check_arg(argc - 1, ar)))
		ft_exit(WRONG_INPUT);
	i = argc != 2 ? argc - 2 : ft_len_arr(ar) - 1;
	while (i >= 0)
		ft_addnew(&stack_a, ft_myatoi(ar[i--]));
	ft_find_dup(stack_a);
	ft_solver(&stack_a);
	ft_delstack(&stack_a);
	argc == 2 && ar ? ft_free_arr(ar) : 0;
	return (0);
}
