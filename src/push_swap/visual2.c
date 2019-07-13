/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 22:18:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/13 22:38:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visual.h"

void	ft_print_stack(t_ps *stacks)
{
	int len;

	len = 4 + ft_get_length_stack(stacks->a) + ft_get_length_stack(stacks->b);
	ft_print_one(stacks->a, len, 3);
	ft_print_one(stacks->b, len, WIDTH_SCREEN / 2 + 8);
	ft_go_to_x_y(len + 1, 0);
	ft_print_line(10, ' ');
	ft_go_to_x_y(len + 1, 2);
	usleep(50000);
}

void	ft_print_head(void)
{
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-');
	ft_printf("|\n|");
	ft_print_line(WIDTH_SCREEN / 2 + 4, ' ');
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN / 2 + 2, ' ');
	ft_printf("|\n");
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-');
	ft_printf("|\n");
	ft_go_to_x_y(2, WIDTH_SCREEN / 4);
	ft_printf("STACK A");
	ft_go_to_x_y(2, WIDTH_SCREEN / 4 * 3 + 6);
	ft_printf("STACK B");
}

void	ft_print_frame(t_ps *stacks)
{
	int len;
	int i;

	i = 0;
	ft_print_head();
	len = ft_get_length_stack(stacks->a);
	ft_go_to_x_y(4, 0);
	while (i++ < len)
	{
		ft_printf("|");
		ft_print_line(WIDTH_SCREEN / 2 + 4, ' ');
		ft_printf("|");
		ft_print_line(WIDTH_SCREEN / 2 + 2, ' ');
		ft_printf("|\n");
	}
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-');
	ft_printf("|\n");
	ft_print_stack(stacks);
}
