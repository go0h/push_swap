/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:12:26 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/05 20:29:17 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_swap(char *dest, char *src)
{
	if (ft_strncmp(src, "sa\nsb", 5) && ft_strncmp(src, "sb\nsa", 5))
		return (0);
	ft_strcpy(dest, "ss");
	return (1);
}

static int	check_rotate(char *dest, char *src)
{
	if (ft_strncmp(src, "ra\nrb", 5) && ft_strncmp(src, "rb\nra", 5))
		return (0);
	if ((src - 1) &&
		(!ft_strncmp(src - 1, "rra", 3) || ft_strncmp(src - 1, "rrb", 3)))
		return (0);
	ft_strcpy(dest, "rr");
	return (1);
}

static int	check_rev_rotate(char *dest, char *src)
{
	if (ft_strncmp(src, "rra\nrrb", 7) && ft_strncmp(src, "rrb\nrra", 7))
		return (0);
	ft_strcpy(dest, "rrr");
	return (1);
}

void		ft_post_processing(t_ps *stacks)
{
	char	*temp;
	char	*line;
	int		i;

	line = stacks->line;
	if (!(temp = ft_strnew(ft_strlen(line))))
		ft_exit(&stacks, MALLOC_FAILURE);
	i = 0;
	while (*line)
	{
		if (check_swap(&temp[i], line) || check_rotate(&temp[i], line))
		{
			i += 2;
			line += 5;
		}
		else if (check_rev_rotate(&temp[i], line))
		{
			i += 3;
			line += 7;
		}
		else
			temp[i++] = *line++;
	}
	free(stacks->line);
	stacks->line = temp;
}
