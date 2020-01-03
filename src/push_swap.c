/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 19:42:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char	**av;
	int		i;

	argc == 1 ? ft_exit(NULL, USAGE_P) : 0;
	if (argc == 2)
	{
		if (!(av = ft_strsplit_sp(argv[1])))
			ft_exit(NULL, MALLOC_FAILURE);
	}
	else
		av = &argv[1];
	if (!(ft_check_arg(argc - 1, av)))
		ft_exit(NULL, WRONG_INPUT);
	i = argc != 2 ? argc - 2 : ft_len_arr(av) - 1;
	ft_solver(i, av);
	argc == 2 ? ft_free_arr(av) : 0;
	return (0);
}
