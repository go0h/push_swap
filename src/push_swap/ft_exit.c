/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:31:01 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/23 16:37:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_exit(int err)
{
	if (err == MALLOC_FAILURE)
		ft_fprintf(2, "Failed to allocate memory.\n");
	else if (err == WRONG_INPUT)
		ft_fprintf(2, "Error\n");
	else if (err == READ_ERROR)
		ft_fprintf(2, "Can't read from stdin.\n");
	else if (err == WRONG_OPERATION)
		ft_fprintf(2, "Error\n");
	exit(err);
}
