/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:12 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 17:46:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"

enum
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

# define USAGE_P 3
# define USAGE_C 4
# define WRONG_INPUT 5
# define READ_ERROR 6
# define WRONG_OPERATION 7
# define WRONG_OPTION 8

# define WIDTH_SCREEN 160
# define HEIGHT_SCREEN 48
# define CLEAR_SCREEN "\e[1;1H\e[2J"

# define NUM(a) (*(int*)a->content)

typedef struct	s_ps
{
	t_list		*a;
	t_list		*b;
	char		*line;
	int			i;
	int			med;
	int			max;
	int			min;
	char		v;
}				t_ps;

void			ft_exit(t_ps **stacks, int err);

/*
** debug funcitons
*/

t_ps			*ft_init_stacks(int ac, char **av);

void			ft_printstack(t_list *begin);

void			ft_printstacks(t_list *a, t_list *b);

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

int				ft_len_arr(char **arr);

int				ft_check_arg(int ac, char **av);

void			ft_find_dup(t_list *stack);

int				ft_myatoi(char *str, t_ps *stacks);

int				ft_check_sort(t_list *stack_a, int len, int rev);

/*
** algorithm functions
*/

int				ft_get_length_stack(t_list *stack);

int				ft_get_mediana(t_list *stack, int len, int flag);

int				ft_basic_case(t_ps *stacks, char cur, int len);

int				ft_sort_three(t_ps *stacks, char cur);

int				ft_case_six(t_ps *stacks, char cur, int len);

void			ft_solver(int ac, char **av);

int				ft_min_max(t_ps *stacks, char cur);

/*
** quick sort algorithm functions
*/

int				ft_sort_a(t_ps *stacks, int len);

int				ft_sort_b(t_ps *stacks, int len);

/*
** selection sort algrithm functions
*/

void			ft_select_sort(t_ps *stacks);

/*
** post algorithm functions
*/

void			ft_post_processing(t_ps *stacks);

int				ft_operation(t_ps *stacks, char *oper);

void			ft_free_stacks(t_ps **to_del);

void			ft_del_content(void * content, size_t size);

/*
** visual stacks functions
*/

void			ft_clear_screen(void);

void			ft_go_to_x_y(int x, int y);

void			ft_print_stack(t_ps *stacks);

void			ft_print_frame(t_ps *stacks);

void			ft_print_one(t_ps *stacks, int len, int x, char cur);

void			ft_print_line(int len, char c, int v);

#endif
