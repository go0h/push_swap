/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/25 00:02:13 by astripeb         ###   ########.fr       */
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
	ft_solver(&stack_a, argc - 1, ft_get_mediana(argc - 1, &argv[1]));
	ft_delstack(&stack_a);
	return (0);
}

void		ft_solver(t_stack **stack, int len, int mediana)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	
	ft_printf("len = %d, mediana = %d\n", len, mediana);
	line = ft_strnew(0);
	stack_b = NULL;
	stack_a = *stack;
	while (!(ft_check_sort(stack_a, stack_b)))
	{
		if (stack_a->next && stack_a->num > stack_a->next->num)
		{
			ft_swap(stack_a);
			line = ft_strjoin_f(line, "sa\n");
		}
	}
	ft_printf("%s", line);
	*stack = stack_a;
}
