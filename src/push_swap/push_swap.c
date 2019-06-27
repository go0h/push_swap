/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/26 21:54:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!(ft_check_arg(argc - 1, &argv[1])))
		ft_exit(WRONG_INPUT);
	i = argc - 1;
	while (i > 0)
	{
		ft_addnew(&stack_a, ft_myatoi(argv[i]));
		--i;
	}
	ft_find_dup(stack_a);
	ft_solver(&stack_a);
	ft_delstack(&stack_a);
	return (0);
}