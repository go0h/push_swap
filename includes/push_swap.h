/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/06/29 17:13:09 by astripeb         ###   ########.fr       */
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

typedef struct	s_vals
{
	int				len;
	int				med;
	char			*line;
}				t_vals;

void			ft_exit(int err);

t_stack			*ft_newlist(int num);

void			ft_addnew(t_stack **begin, int num);

void			ft_delonelist(t_stack **begin);

void			ft_delstack(t_stack **begin);

void			ft_printstack(t_stack *begin);

void			ft_printstacks(t_stack *stack_a, t_stack *stack_b);

void			ft_swap(t_stack *stack_a, t_vals *val, char *op);

void			ft_swap_two(t_stack *a, t_stack *b, t_vals *val, char *op);

void			ft_push(t_stack **a, t_stack **b, t_vals *val, char *op);

void			ft_rotate(t_stack **stack_a, t_vals *val, char *op);

void			ft_rotate_two(t_stack **a, t_stack **b, t_vals *val, char *op);

void			ft_rev_rotate(t_stack **stack_a, t_vals *val, char *op);

void			ft_rev_rotate_two(t_stack **a, t_stack **b,\
				t_vals *val, char *op);

int				ft_check_arg(int ac, char **av);

void			ft_find_dup(t_stack *stack);

int				ft_myatoi(char *str);

int				ft_operation(char *oper, t_stack **stack_a, t_stack **stack_b);

int				ft_check_sort(t_stack *stack_a, int len);

void			ft_solver(t_stack **stack_a);

int				ft_get_last_num(t_stack *stack);

int				ft_get_length_stack(t_stack *stack);

int				ft_get_mediana(t_stack *stack, int len);

t_vals			*ft_gen_vals(t_stack *stack);

int				ft_merge_sort(int *arr, int len);

int				ft_split_med_a(t_stack **s_a, t_stack **s_b, t_vals *val, int len);

int				ft_basic_case(t_stack **a, t_vals *val, int len);

//void			ft_split_med(t_stack **stack_a, t_stack **stack_b,
//				t_vals *val_s);
#endif
