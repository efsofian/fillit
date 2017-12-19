# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2017/02/08 18:17:09 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main trad_and_init is_right_bloc find_checkboard print_map

SRC_NAME = $(addsuffix .c, $(FILES))
OBJ_NAME = $(addsuffix .o, $(FILES))

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
HDR_PATH = ./srcs/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_TO_DELETE = $(addsuffix _to_delete, $(OBJ))

CC = gcc

CC_FLAG = -Wall -Wextra -Werror
CPP_FLAG = -I$(HDR_PATH)
FLAGS = $(CC_FLAG) $(CPP_FLAG)
FLAGS_LIBFT = -L./libft/ -lft

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C./libft/ re
	@$(CC) $(FLAGS) $(FLAGS_LIBFT) $^ -o $@
	@make -C./libft/ fclean
	@echo "\033[0;32m""created   : $(NAME) in the directory ./""\033[m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) 2> /tmp/a.del
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[0;33m""created   : $@""\033[m"

clean: $(OBJ_TO_DELETE)
ifneq ($(OBJ_PATH), ./)
	@rm -Rf $(OBJ_PATH)
	@echo "\033[0;31m""deleted   : the directory $(OBJ_PATH)""\033[m"
endif

$(OBJ_PATH)%.o_to_delete:
	@rm -f $(@:.o_to_delete=.o)
	@echo "\033[1;31m""deleted   : $(@:.o_to_delete=.o)""\033[m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m""deleted   : $(NAME)""\033[m"

re:
	@make fclean
	@make all

new_auteur:
	@rm -f auteur
	@echo "enanrock;seliasbe" > auteur
	cat -e auteur

norme:
	@norminette $(SRC_PATH)                              \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[0;32mNorme"`/g''
	@norminette $(HDR_PATH)                              \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[1;34mNorme"`/g''
