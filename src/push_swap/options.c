/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:44:50 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/14 12:12:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_options(int ac, char **av)
{
	int i;
	int v;
	int c;

	i = 0;
	v = 0;
	c = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			v = 1;
		else if (!ft_strcmp(av[i], "-c"))
			c = 1;
		else if (av[i][0] == '-' && (av[i][1] != 'v' || av[i][1] != 'c') &&
				!ft_isdigit(av[i][1]))
			ft_exit(NULL, USAGE_C);
		++i;
	}
	if ((!v && c) || (v + c == ac))
		ft_exit(NULL, USAGE_C);
	return (v + c + 1);
}
