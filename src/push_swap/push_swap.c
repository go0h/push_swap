/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:38 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/26 21:54:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, char **line, int f);

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!(ft_check_arg(argc - 1, &argv[1])))
		ft_exit(WRONG_INPUT);
	i = argc - 1;
	while (i > 0)
	{
		ft_addnew(&stack_a, ft_myatoi(argv[i]));
		--i;
	}
	ft_find_dup(stack_a);
	ft_solver(&stack_a);
	ft_delstack(&stack_a);
	return (0);
}

void		ft_solver(t_stack **stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (!(line = ft_strnew(0)))
		ft_exit(MALLOC_FAILURE);
	stack_b = NULL;
	stack_a = *stack;
	ft_split_med(&stack_a, &stack_b, &line, 1);
	line = ft_strjoin_f(line, "-\n");
	while (ft_get_length_stack(stack_b) != 1)
	{
		ft_get_half_stack(&stack_b, &stack_a, &line, 0);
	}
	ft_printf("%s", line);
	*stack = stack_a;
}
	
void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, char **line, int f)
{
	int		len;
	int		med;
	t_stack *stack_a;

	stack_a = *s_a;
	len = ft_get_length_stack(stack_a) / 2;
	med = ft_get_mediana(stack_a);
	while (len)
	{
		ft_printstacks(f ? stack_a : *s_b, f ? *s_b : stack_a);
		if (stack_a && stack_a->num <= med)
		{
			ft_rotate(&stack_a);
			if (!(*line = ft_strjoin_f(*line, f ? "ra\n" : "rb\n")))
				ft_exit(MALLOC_FAILURE);
		}
		else
		{
			ft_push(&stack_a, s_b);
			ft_rotate(s_b);
			if (!(*line = ft_strjoin_f(*line, f ? "pa\nra\n" : "pb\nrb\n")))
				ft_exit(MALLOC_FAILURE);
			--len;
		}
	}
	ft_printstacks(f ? stack_a : *s_b, f ? *s_b : stack_a);
	*s_a = stack_a;
}
