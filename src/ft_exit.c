/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:31:01 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/14 12:08:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_exit(t_ps **stacks, int err)
{
	ft_free_stacks(stacks);
	if (err == USAGE_C)
		ft_fprintf(2, "usage: ./checker [-v [-c]]  [digit_1 ... digit_n]\n");
	if (err == USAGE_P)
		ft_fprintf(2, "usage: ./push_swap [digit_1 ... digit_n]\n");
	else if (err == MALLOC_FAILURE)
		ft_fprintf(2, "Failed to allocate memory.\n");
	else if (err == WRONG_INPUT)
		ft_fprintf(2, "Error\n");
	else if (err == READ_ERROR)
		ft_fprintf(2, "Can't read from stdin.\n");
	else if (err == WRONG_OPERATION)
		ft_fprintf(2, "Error\n");
	exit(err);
}
