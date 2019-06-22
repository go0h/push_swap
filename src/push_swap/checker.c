/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:21:24 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 18:41:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	if (argc == 1 || !check_arg(argc - 1, &argv[1]))
	{
		ft_fprintf(2, "Invalid input\n");
		return (0);
	}
	return (0);
}
