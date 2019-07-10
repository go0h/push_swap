/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:12:26 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 00:02:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_post_processing(t_ps *stacks)
{
	int		i;
	char		*line;

	line = stacks->line;
	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == SA && line[i + 1] == SB) || (line[i] == SB && line[i + 1] == SB))
		{
			write(1, "ss\n", 3);
			i += 2;
			continue;
		}
		if ((line[i] == RA && line[i + 1] == RB) || (line[i] == RB && line[i + 1] == RA))
		{
			write(1, "rr\n", 3);
			i += 2;
			continue;
		}
		if ((line[i] == RRA && line[i + 1] == RRB) || (line[i] == RRB && line[i + 1] == RRA))
		{
			write(1, "rrr\n", 4);
			i += 2;
			continue;
		}
		if ((line[i] == PA && line[i + 1] == PB) || (line[i] == PB && line[i + 1] == PA))
		{
			i += 2;
			continue;
		}
		if ((line[i] == RA && line[i + 1] == RRA) || (line[i] == RB && line[i + 1] == RRB))
		{
			i += 2;
			continue;
		}
		if ((line[i] == RRA && line[i + 1] == RA) || (line[i] == RRB && line[i + 1] == RB))
		{
			i += 2;
			continue;
		}
		line[i] == SA ? write(1, "sa\n", 3) : 0;
		line[i] == SB ? write(1, "sb\n", 3) : 0;
		line[i] == PA ? write(1, "pa\n", 3) : 0;
		line[i] == PB ? write(1, "pb\n", 3) : 0;
		line[i] == RA ? write(1, "ra\n", 3) : 0;
		line[i] == RB ? write(1, "rb\n", 3) : 0;
		line[i] == RRA ? write(1, "rra\n", 4) : 0;
		line[i] == RRB ? write(1, "rrb\n", 4) : 0;
		++i;
	}
}
