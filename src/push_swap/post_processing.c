/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:12:26 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/11 19:24:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_combo(char *s, int len)
{
	int 	i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (i >= 0 && j < len)
		{
			if ((s[i] == SA && s[j] == SB) || (s[i] == SB && s[j] == SB))
				s[i--] = SS;
			else if ((s[i] == RA && s[j] == RB) || (s[i] == RB && s[j] == RA))
				s[i--] = RR;
			else if ((s[i] == RRA && s[j] == RRB)
				|| (s[i] == RRB && s[j] == RRA))
				s[i--] = RRR;
			else if ((s[i] == RA && s[j] == RRA) || (s[i] == RB && s[j] == RRB)
				|| (s[i] == RRA && s[j] == RA) || (s[i] == RRB && s[j] == RB))
				s[i--] = 0;
			else
				break ;
			s[j++] = 0;
		}
		++i;
	}
}

void		ft_post_processing(t_ps *stacks)
{
	int		i;
	char	*line;

	line = stacks->line;
	ft_check_combo(line, stacks->i);
	i = 0;
	while (i < stacks->i)
	{
		if ((line[i] == PA && line[i + 1] == PB) ||
			(line[i] == PB && line[i + 1] == PA))
		{
			i += 2;
			continue ;
		}
		line[i] == SA ? write(1, "sa\n", 3) : 0;
		line[i] == SB ? write(1, "sb\n", 3) : 0;
		line[i] == SS ? write(1, "ss\n", 3) : 0;
		line[i] == PA ? write(1, "pa\n", 3) : 0;
		line[i] == PB ? write(1, "pb\n", 3) : 0;
		line[i] == RA ? write(1, "ra\n", 3) : 0;
		line[i] == RB ? write(1, "rb\n", 3) : 0;
		line[i] == RR ? write(1, "rr\n", 3) : 0;
		line[i] == RRA ? write(1, "rra\n", 4) : 0;
		line[i] == RRB ? write(1, "rrb\n", 4) : 0;
		line[i++] == RRR ? write(1, "rrr\n", 4) : 0;
	}
}