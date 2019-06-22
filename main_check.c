/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:26:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 18:41:59 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *temp;
	int i;
	
	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	temp = stack_a;
	while (i < argc)
	{
		ft_addnew(&stack_a, ft_atoi(argv[i]));
		ft_addnew(&stack_b, ft_atoi(argv[i]));
		++i;
	}
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("push a -> b\n");
	ft_push(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("swap a and b\n");
	ft_swap_two(stack_a, stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("push b -> a\n");
	ft_push(&stack_b, &stack_a);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("rotate a\n");
	ft_rotate(&stack_a);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("rotate a\n");
	ft_rotate(&stack_a);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("push a -> b\n");
	ft_push(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("push a -> b\n");
	ft_push(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("rotate a and b\n");
	ft_rotate_two(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("reverse rotate a\n");
	ft_rev_rotate(&stack_a);
	ft_printstacks(stack_a, stack_b);
	
	ft_printf("reverse rotate a and b\n");
	ft_rev_rotate_two(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
	
	ft_delstack(&stack_a);
	ft_delstack(&stack_b);
	return (0);
}
