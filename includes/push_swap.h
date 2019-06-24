/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/24 23:29:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libftprintf.h"

# define MALLOC_FAILURE 2
# define WRONG_INPUT 3
# define READ_ERROR 4
# define WRONG_OPERATION 5

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

void			ft_exit(int err);

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

int				ft_check_arg(int ac, char **av);

void			ft_find_dup(t_stack *stack);

int				ft_myatoi(char *str);

int				ft_operation(char *oper, t_stack **stack_a, t_stack **stack_b);

int				ft_check_sort(t_stack *stack_a, t_stack *stack_b);

void			ft_solver(t_stack **stack_a, int len, int mediana);

int				ft_get_last_num(t_stack *stack);

int				ft_get_mediana(int ac, char **av);

int				ft_merge_sort(int *arr, int len);
#endif
