/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:21:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/06 12:24:28 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

static void		ft_read_instructions(t_ps *stacks)
{
	int		n;
	char	*line;

	line = NULL;
	while ((n = get_next_line(0, &line)) > 0)
	{
		if (!(ft_operation(stacks, line, 0)))
			ft_exit(&stacks, WRONG_OPERATION);
		free(line);
	}
	if (n < 0)
		ft_exit(&stacks, READ_ERROR);
	if (!stacks->b && ft_check_sort(stacks->a, ft_get_length_stack(stacks->a)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stacks(&stacks);
}

int				main(int argc, char **argv)
{
	t_ps		*stacks;
	char		**ar;
	int			i;

	if (!(stacks = (t_ps*)malloc(sizeof(t_ps))))
		ft_exit(NULL, MALLOC_FAILURE);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->line = NULL;
	argc == 1 ? exit(0) : 0;
	if (argc == 2)
	{
		if (!(ar = ft_strsplit_sp(argv[1])))
			ft_exit(&stacks, MALLOC_FAILURE);
	}
	else
		ar = &argv[1];
	if (!(ft_check_arg(argc - 1, ar)))
		ft_exit(&stacks, WRONG_INPUT);
	i = argc != 2 ? argc - 2 : ft_len_arr(ar) - 1;
	while (i >= 0)
		ft_addnew(&stacks->a, ft_myatoi(ar[i--]));
	ft_find_dup(stacks->a);
	ft_read_instructions(stacks);
	return (0);
}
