/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:21:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 16:18:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	int		n;
	char	*line;

	while ((n = get_next_line(0, &line)) > 0)
	{
		if (!(ft_operation(line, stack_a, stack_b)))
			ft_exit(WRONG_OPERATION);
		ft_printstacks(*stack_a, *stack_b);
	}
	if (n < 0)
		ft_exit(READ_ERROR);
	if (!*stack_b && ft_check_sort(*stack_a, ft_get_length_stack(*stack_a)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
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
	ft_read_instructions(&stack_a, &stack_b);
	return (0);
}
