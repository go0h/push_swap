/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/22 18:27:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libftprintf.h"

# define MALLOC_FAILURE 2

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

t_stack			*ft_newlist(int num);

void			ft_addnew(t_stack **begin, int num);

void			ft_delonelist(t_stack **begin);

void			ft_delstack(t_stack **begin);

void			ft_printstack(t_stack *begin);

void			ft_printstacks(t_stack *stack_a, t_stack *stack_b);

void			ft_swap(t_stack *stack_a);

void			ft_swap_two(t_stack *stack_a, t_stack *stack_b);

void			ft_push(t_stack **stack_a, t_stack **stack_b);

void			ft_rotate(t_stack **stack_a);

void			ft_rotate_two(t_stack **stack_a, t_stack **stack_b);

void			ft_rev_rotate(t_stack **stack_a);

void			ft_rev_rotate_two(t_stack **stack_a, t_stack **b);

int				check_arg(int ac, char **av);
#endif
