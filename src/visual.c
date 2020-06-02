/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 22:18:08 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:27:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_screen(void)
{
	ft_printf("%s", CLEAR_SCREEN);
}

void	ft_go_to_x_y(int x, int y)
{
	ft_printf("\e[%d;%dH", x, y);
}

void	ft_print_line(int i, char c, int v)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1, &c, 1);
		++j;
	}
	v == 2 ? write(1, "\e[49m", 5) : 0;
	while (j++ < WIDTH_SCREEN / 2)
		write(1, " ", 1);
}

void	ft_print_one(t_ps *stacks, int len, int x, char cur)
{
	int		i;
	t_list	*stack;
	int		c;

	stack = cur == 'a' ? stacks->a : stacks->b;
	i = 4;
	while (stack)
	{
		ft_go_to_x_y(i, x);
		c = 20 + NUM(stack);
		stacks->v == 2 ? ft_printf("\e[48;5;%dm\e[8m", c) : 0;
		ft_print_line(NUM(stack), '*', stacks->v);
		stack = stack->next;
		++i;
		stacks->v == 2 ? write(1, "\e[0m", 5) : 0;
	}
	while (i < len)
	{
		ft_go_to_x_y(i, x);
		ft_print_line(0, ' ', 0);
		++i;
	}
}

void	ft_printstacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("-------------------------\n");
	ft_printf("|     a     |     b     |\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("|%11d|%11d|\n", NUM(stack_a), NUM(stack_b));
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && !stack_b)
		{
			ft_printf("|%11d|           |\n", NUM(stack_a));
			stack_a = stack_a->next;
		}
		else if (!stack_a && stack_b)
		{
			ft_printf("|           |%11d|\n", NUM(stack_b));
			stack_b = stack_b->next;
		}
	}
	ft_printf("-------------------------\n");
}
