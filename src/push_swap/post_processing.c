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

int			ft_check_combo(char *s, int i, int j)
{
	int		flag;

	flag = 0;
	if ((s[i] == SA && s[j] == SB) || (s[i] == SB && s[j] == SB))
		flag = ft_putstr("ss\n");
	if ((s[i] == RA && s[j] == RB) || (s[i] == RB && s[j] == RA))
		flag = ft_putstr("rr\n");
	if ((s[i] == RRA && s[j] == RRB) || (s[i] == RRB && s[j] == RRA))
		flag = ft_putstr("rrr\n");
	if ((s[i] == RRA && s[j] == RRB) || (s[i] == RRB && s[j] == RRA))
		flag = ft_putstr("rrr\n");
	if ((s[i] == PA && s[j] == PB) || (s[i] == PB && s[j] == PA))
		flag = 1;
	if ((s[i] == RA && s[j] == RRA) || (s[i] == RB && s[j] == RRB))
		flag = 1;
	if ((s[i] == RRA && s[j] == RA) || (s[i] == RRB && s[j] == RB))
		flag = 1;
	return (flag ? 1 : 0);
}

void		ft_post_processing(t_ps *stacks)
{
	int		i;
	char	*line;

	line = stacks->line;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_check_combo(line, i, i + 1))
		{
			i += 2;
			continue ;
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
