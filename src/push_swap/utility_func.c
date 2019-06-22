/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:37:31 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 18:38:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_arg(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			++j;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || j > 19)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}
