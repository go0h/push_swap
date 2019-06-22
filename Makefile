# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/06/22 11:50:21 by astripeb         ###   ########.fr        #
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

SOURCES = random.c

SRCS = $(addprefix $(LIBFT_PATH)/,$(SOURCES_LIBFT))

OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all: $(NAME_S)

$(NAME_S): bin # $(OBJ)

lib:
	@make -f $(MLIB)

bin:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(LIBFT_PATH)/%.c
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
