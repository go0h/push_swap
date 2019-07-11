/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:21:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 21:42:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_read_instructions(t_ps *stacks)
{
	int		n;
	char	*line;

	line = NULL;
	while ((n = get_next_line(0, &line)) > 0)
	{
		if (!(ft_operation(stacks, line)))
			ft_exit(&stacks, WRONG_OPERATION);
		free(line);
	}
	if (n < 0)
		ft_exit(&stacks, READ_ERROR);
	if (!stacks->b &&
		ft_check_sort(stacks->a, ft_get_length_stack(stacks->a), 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int argc, char **argv)
{
	t_ps		*stacks;
	char		**av;
	int			i;

	argc == 1 ? ft_exit(NULL, USAGE_C) : 0;
	if (argc == 2)
	{
		if (!(av = ft_strsplit_sp(argv[1])))
			ft_exit(&stacks, MALLOC_FAILURE);
	}
	else
		av = &argv[1];
	if (!(ft_check_arg(argc - 1, av)))
		ft_exit(NULL, WRONG_INPUT);
	i = argc != 2 ? argc - 2 : ft_len_arr(av) - 1;
	stacks = ft_init_stacks(i, av);
	ft_read_instructions(stacks);
	ft_free_stacks(&stacks);
	argc == 2 ? ft_free_arr(av) : 0;
	return (0);
}
