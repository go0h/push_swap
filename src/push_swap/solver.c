
#include "push_swap.h"

void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, char **line, int f);

void		ft_solver(t_stack **stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int	med;

	if (!(line = ft_strnew(0)))
		ft_exit(MALLOC_FAILURE);
	stack_b = NULL;
	stack_a = *stack;
	med = ft_get_mediana(stack_a);
//	while (med)
//	{
		ft_split_med(&stack_a, &stack_b, &line, med);
		while (ft_get_length_stack(stack_b) != 1)
			ft_get_half_stack(&stack_b, &stack_a, &line, med);
		ft_push(&stack_b, &stack_a);
		ft_rotate(&stack_a);
		med /= 2;
//	}
	ft_printf("%s", line);
	*stack = stack_a;
}

void	ft_split_med(t_stack **s_a, t_stack **s_b, char **line, int med)
{
	t_stack	*stack_a;
	int		len;
	
	stack_a = *s_a;
	len = ft_get_length_stack(stack_a);
	len = (len % 2 == 1 && len != 1) ? len / 2 + 1 : len / 2;
	while (len)
	{
		ft_printstacks(stack_a, *s_b);
		if (stack_a && stack_a->num <= med)
		{
			ft_push(&stack_a, s_b);
			if (!(*line = ft_strjoin_f(*line, "pb\n")))
				ft_exit(MALLOC_FAILURE);
			--len;
		}
		else
		{
			ft_rotate(&stack_a);
			if (!(*line = ft_strjoin_f(*line, "ra\n")))
				ft_exit(MALLOC_FAILURE);
		}
	}
	*s_a = stack_a;
}

void		ft_get_half_stack(t_stack **s_a, t_stack **s_b, char **line, int med)
{
	int		len;
//	int		med;
	t_stack *stack_a;

	stack_a = *s_a;
	len = ft_get_length_stack(stack_a) / 2 - 1;
	med = ft_get_mediana(stack_a);
	while (ft_get_length_stack(stack_a) > len)
	{
		ft_printstacks(*s_b, stack_a);
		if (stack_a && stack_a->num <= med)
		{
			ft_rotate(&stack_a);
			if (!(*line = ft_strjoin_f(*line, "ra\n")))
				ft_exit(MALLOC_FAILURE);
		}
		else
		{
			ft_push(&stack_a, s_b);
			if (!(*line = ft_strjoin_f(*line, "pa\n")))
				ft_exit(MALLOC_FAILURE);
//			--len;
		}
	}
	ft_printstacks(*s_b, stack_a);
	*s_a = stack_a;
}
