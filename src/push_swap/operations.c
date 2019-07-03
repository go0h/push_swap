/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:19:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/03 23:30:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_operation(t_ps *stacks, char *oper)
{
	if (!(ft_strcmp("sa", oper)))
	{
		ft_printf("swap a\n");
		ft_swap(stacks, 'a');
	}
	else if (!(ft_strcmp("sb", oper)))
	{
		ft_printf("swap b\n");
		ft_swap(stacks, 'b');
	}
	else if (!(ft_strcmp("ss", oper)))
	{
		ft_printf("swap a and b\n");
		ft_swap_two(stacks);
	}
	else if (!(ft_strcmp("pa", oper)))
	{
		ft_printf("push a -> b\n");
		ft_push(stacks, 'a');
	}
	else if (!(ft_strcmp("pb", oper)))
	{
		ft_printf("push b -> a\n");
		ft_push(stacks, 'b');
	}
	else if (!(ft_strcmp("ra", oper)))
	{
		ft_printf("rotate a\n");
		ft_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rb", oper)))
	{
		ft_printf("rotate b\n");
		ft_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rr", oper)))
	{
		ft_printf("rotate a and b\n");
		ft_rotate_two(stacks);
	}
	else if (!(ft_strcmp("rra", oper)))
	{
		ft_printf("reverse rotate a\n");
		ft_rev_rotate(stacks, 'a');
	}
	else if (!(ft_strcmp("rrb", oper)))
	{
		ft_printf("reverse rotate b\n");
		ft_rev_rotate(stacks, 'b');
	}
	else if (!(ft_strcmp("rrr", oper)))
	{
		ft_printf("reverse rotate a and b\n");
		ft_rev_rotate_two(stacks);
	}
	else
		ft_exit(WRONG_OPERATION);
	return (1);
}

int		ft_check_sort(t_stack *stack_a, int len)
{
	int n;
	int i;

	i = 0;
	n = stack_a->num;
	stack_a = stack_a->next;
	while (stack_a && i < len)
	{
		if (n >= stack_a->num)
			return (0);
		n = stack_a->num;
		stack_a = stack_a->next;
		++i;
	}
	return (1);
}

int		ft_get_length_stack(t_stack *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}

void		ft_post_processing(t_ps *stacks)
{
	char		*temp;
	char		*line;
	int		i;
	int		j;

	line = stacks->line;
	if (!(temp = ft_strnew(ft_strlen(line))))
		ft_exit(MALLOC_FAILURE);
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (ft_strncmp(&line[i], "sa\nsb", 5) && ft_strncmp(&line[i], "ra\nrb", 5))
			temp[j++] = line[i++];
		else
		{
			ft_strcpy(&temp[j], line[i] == 's' ? "ss\n" : "rr\n");
			i += 6;
			j += 3;
		}
	}
	temp[j] = '\0';
	free(line);
	stacks->line = temp;
}
