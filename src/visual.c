/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 22:18:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/14 14:39:50 by astripeb         ###   ########.fr       */
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
	t_stack	*stack;
	int		c;

	stack = cur == 'a' ? stacks->a : stacks->b;
	i = 4;
	while (stack)
	{
		ft_go_to_x_y(i, x);
		c = 20 + stack->num;
		stacks->v == 2 ? ft_printf("\e[48;5;%dm\e[8m", c) : 0;
		ft_print_line(stack->num, '*', stacks->v);
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
