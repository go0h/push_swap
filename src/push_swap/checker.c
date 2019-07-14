/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:21:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/14 14:36:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visual.h"

static void		ft_read_instructions(t_ps *stacks)
{
	int		n;
	char	*line;

	line = NULL;
	stacks->v ? (ft_print_frame(stacks), ft_printf("\e[1m")) : 0;
	while ((n = get_next_line(0, &line)) > 0)
	{
		if (!(ft_operation(stacks, line)))
			ft_exit(&stacks, WRONG_OPERATION);
		free(line);
	}
	if (n < 0)
		ft_exit(&stacks, READ_ERROR);
	stacks->v ? ft_printf("\e[0m") : 0;
	stacks->v ? ft_printf("\e[5m") : 0;
	if (!stacks->b &&
		ft_check_sort(stacks->a, ft_get_length_stack(stacks->a), 0))
		ft_printf("%sOK\n\e[0m", stacks->v == 2 ? "\e[32m" : "");
	else
		ft_printf("%sKO\n\e[0m", stacks->v == 2 ? "\e[31m" : "");
}

int				main(int argc, char **argv)
{
	t_ps		*stacks;
	char		**av;
	int			i;
	int			j;

	argc == 1 ? ft_exit(NULL, USAGE_C) : 0;
	j = ft_options(argc - 1, &argv[1]) + 1;
	if (argc - j == 0)
	{
		if (!(av = ft_strsplit_sp(argv[j - 1])))
			ft_exit(&stacks, MALLOC_FAILURE);
	}
	else
		av = &argv[j - 1];
	i = argc - j != 0 ? argc - j : ft_len_arr(av) - 1;
	if (!(ft_check_arg(i, av)))
		ft_exit(NULL, WRONG_INPUT);
	stacks = ft_init_stacks(i, av);
	stacks->v = j - 2;
	ft_read_instructions(stacks);
	ft_free_stacks(&stacks);
	argc == 2 ? ft_free_arr(av) : 0;
	return (0);
}
