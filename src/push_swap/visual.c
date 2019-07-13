/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 22:18:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/13 22:25:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visual.h"

void	ft_clear_screen(void)
{
	ft_printf("%s", CLEAR_SCREEN);
}

void	ft_go_to_x_y(int x, int y)
{
	ft_printf("\e[%d;%dH", x, y);
}

void	ft_print_line(int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1, &c, 1);
		++j;
	}
	while (j++ < WIDTH_SCREEN / 2)
		write(1, " ", 1);
}

void	ft_print_one(t_stack *stack, int len, int x)
{
	int i;

	i = 4;
	while (stack)
	{
		ft_go_to_x_y(i, x);
		ft_print_line(stack->num, '*');
		stack = stack->next;
		++i;
	}
	while (i < len)
	{	
		ft_go_to_x_y(i, x);
		ft_print_line(0, ' ');
		++i;
	}
}
