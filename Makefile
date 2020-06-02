# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2020/06/02 17:30:35 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN           := \033[0;32m
RED             := \033[0;31m
RESET           := \033[0m

PUSH_SWAP		:= push_swap
CHECKER			:= checker

INC_DIR 		:= ./includes
SRC_DIR 		:= ./src
OBJ_DIR			:= ./obj
LIBFT_DIR		:= ./libft

CC 				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
LFLAGS 			:= -I $(INC_DIR) -I $(LIBFT_DIR)/inc
LIB				:= -L $(LIBFT_DIR) -lft

LIBFT	 		:= libft.a

HEADERS			:= push_swap.h

SRCS			:= push_swap_func.c rev_rotation.c utility_func.c\
				utility_func2.c ft_exit.c ft_select_sort.c special_cases.c\
				visual.c visual2.c

SRC_C 			:= checker.c operations.c

SRC_S 			:= push_swap.c solver.c post_processing.c

OBJS			:= $(SRCS:.c=.o)
OBJ_C			:= $(SRC_C:.c=.o)
OBJ_S			:= $(SRC_S:.c=.o)

vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath %.h $(INC_DIR)
vpath %.a $(LIBFT_DIR)

all: lib $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(LIBFT) $(OBJS) $(OBJ_S) $(HEADERS)
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJS) $(OBJ_S)) $(LIB) -o $@
	echo "$(GREEN)$@ was created ✅$(RESET)"

$(CHECKER): $(LIBFT) $(OBJS) $(OBJ_C) $(HEADERS)
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJS) $(OBJ_C)) $(LIB) -o $@
	echo "$(GREEN)$@ was created ✅$(RESET)"

lib:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<
	echo "$(GREEN)$@ was created$(RESET)"

$(OBJ_S):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<
	echo "$(GREEN)$@ was created$(RESET)"

$(OBJ_C):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<
	echo "$(GREEN)$@ was created$(RESET)"

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -rf $(PUSH_SWAP) $(CHECKER)

re: fclean all

.SILENT: all clean fclean re $(PUSH_SWAP) $(CHECKER) $(OBJ_DIR) $(OBJS)\
		$(OBJ_S) $(OBJ_C) lib

.PHONY: all clean fclean re $(PUSH_SWAP) $(CHECKER) $(OBJ_DIR) $(OBJS)\
		$(OBJ_S) $(OBJ_C) lib
