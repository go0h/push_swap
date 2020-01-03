/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 22:18:08 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/20 21:59:51 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_print_stack(t_ps *stacks)
{
	int len;

	len = 4 + ft_get_length_stack(stacks->a) + ft_get_length_stack(stacks->b);
	ft_print_one(stacks, len, 3, 'a');
	ft_print_one(stacks, len, WIDTH_SCREEN / 2 + 8, 'b');
	ft_go_to_x_y(len + 1, 0);
	ft_print_line(10, ' ', 0);
	ft_go_to_x_y(len + 1, 2);
	usleep(100000);
}

static void		ft_print_head(void)
{
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-', 0);
	ft_printf("|\n|");
	ft_print_line(WIDTH_SCREEN / 2 + 4, ' ', 0);
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN / 2 + 2, ' ', 0);
	ft_printf("|\n");
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-', 0);
	ft_printf("|\n");
	ft_go_to_x_y(2, WIDTH_SCREEN / 4);
	ft_printf("STACK A");
	ft_go_to_x_y(2, WIDTH_SCREEN / 4 * 3 + 6);
	ft_printf("STACK B");
}

void			ft_print_frame(t_ps *stacks)
{
	int len;
	int i;

	i = 0;
	ft_clear_screen();
	ft_print_head();
	len = ft_get_length_stack(stacks->a);
	ft_go_to_x_y(4, 0);
	while (i++ < len)
	{
		ft_printf("|");
		ft_print_line(WIDTH_SCREEN / 2 + 4, ' ', 0);
		ft_printf("|");
		ft_print_line(WIDTH_SCREEN / 2 + 2, ' ', 0);
		ft_printf("|\n");
	}
	ft_printf("|");
	ft_print_line(WIDTH_SCREEN + 7, '-', 0);
	ft_printf("|\n");
	ft_print_stack(stacks);
}
