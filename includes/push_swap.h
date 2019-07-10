/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/07/10 23:08:25 by astripeb         ###   ########.fr       */
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

# define SA 1
# define SB 2
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RRA 9
# define RRB 10

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_ps
{
	t_stack		*a;
	t_stack		*b;
	char			*line;
	int			i;
	int			med;
	int			max;
	int			min;
	int			count;
}				t_ps;

void			ft_exit(t_ps **stacks, int err);

/*
** list funcitons
*/

t_stack			*ft_newlist(int num);

void			ft_addnew(t_stack **begin, int num);

void			ft_delonelist(t_stack **begin);

void			ft_delstack(t_stack **begin);

/*
** debug funcitons
*/

void			ft_printstack(t_stack *begin);

void			ft_printstacks(t_stack *a, t_stack *b);

/*
** push_swap operations
*/

int				ft_swap(t_ps *stacks, char cur_s);

int				ft_swap_two(t_ps *stacks);

int				ft_push(t_ps *stacks, char cur_s);

int				ft_rotate(t_ps *stacks, char cur_s);

int				ft_rotate_two(t_ps *stacks);

int				ft_rev_rotate(t_ps *stacks, char cur_s);

int				ft_rev_rotate_two(t_ps *stacks);

/*
** valid arguments functions
*/

int				ft_check_arg(int ac, char **av);

void			ft_find_dup(t_stack *stack);

int				ft_myatoi(char *str);

int				ft_check_sort(t_stack *stack_a, int len);

/*
** algorithm functions
*/

int				ft_get_length_stack(t_stack *stack);

int				ft_get_mediana(t_stack *stack, int len);

int				ft_basic_case(t_ps *stacks, char cur_s, int len);

int				ft_sort_three(t_ps *stacks, char cur);

void			ft_solver(t_stack **stack_a);

int				ft_merge_sort(int *arr, int len);

int				ft_min_max(t_ps *stacks, char cur);

/*
** quick sort algorithm functions
*/

int				ft_sort_a(t_ps *stacks, int len);

int				ft_sort_b(t_ps *stacks, int len);

/*
** insertion sort algrithm functions
*/

int				ft_insert_sort(t_ps *stacks, int len);

/*
** post algorithm functions
*/

void			ft_post_processing(t_ps *stacks);

int				ft_operation(t_ps *stacks, char *oper, int flag);

void			ft_free_stacks(t_ps ** to_del);

#endif
