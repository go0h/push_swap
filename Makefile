# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/06/24 22:01:42 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = push_swap
NAME_C = checker

CC = gcc
OBJ_PATH = ./obj_p
INC_PATH = ./includes
SRC_PATH = ./src/push_swap
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(INC_PATH)

NAME_LIB = libftprintf.a
MLIB = libmake

SOURCES_C = checker.c list_func.c push_swap_func.c rev_rotation.c \
			utility_func.c operations.c ft_exit.c ft_merge_sort.c

SOURCES_S = push_swap.c list_func.c push_swap_func.c rev_rotation.c \
			utility_func.c ft_exit.c operations.c ft_merge_sort.c

SRCS_C = $(addprefix $(SRC_PATH)/,$(SOURCES_C))

SRCS_S = $(addprefix $(SRC_PATH)/,$(SOURCES_S))

OBJ_C = $(addprefix $(OBJ_PATH)/,$(SOURCES_C:.c=.o))

OBJ_S = $(addprefix $(OBJ_PATH)/,$(SOURCES_S:.c=.o))

all: $(NAME_c)

$(NAME_S): bin $(OBJ_S)
	$(CC) $(CFLAGS) $(SRCS_S)  -L./ -lftprintf -o $(NAME_S)

$(NAME_C): bin $(OBJ_C)
	$(CC) $(CFLAGS) $(SRCS_C) -L./ -lftprintf -o $(NAME_C)

lib:
	@make -f $(MLIB)

bin:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

norm:
	@norminette $(SRC_PATH)
	@norminette $(INC_PATH)

gen:
	$(CC) $(CFLAGS) -L./ -lftprintf $(SRC_PATH)/num_gen.c -o num_gen

clean:
	@make -f $(MLIB) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -f $(MLIB) fclean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME_S) $(NAME_C)

re: fclean all
