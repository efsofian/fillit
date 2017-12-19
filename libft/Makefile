# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/19 09:17:32 by enanrock          #+#    #+#              #
#    Updated: 2017/01/10 16:00:37 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp  \
	   ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
	   ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi  \
	   ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper       \
	   ft_tolower ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr          \
	   ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ        \
	   ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr\
	   ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd           \
	   ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter      \
	   ft_lstmap progress_bar ft_strnnjoin ft_strnchr sqrt

SRCS = $(addsuffix .c, $(FILE))

OBJS = $(addsuffix .o, $(FILE))

FLAGS = -Wall -Wextra -Werror

CC = gcc

AR = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[0;32m""created   : $(NAME)""\033[m"
	@ranlib $(NAME)
	@echo "\033[1;32m""sorted    : $(NAME)""\033[m"

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[0;33m""created   : $@""\033[m"

clean: $(addsuffix _to_delete, $(OBJS))

%.o_to_delete:
	@echo "\033[1;31m""deleted   : \c"
	@rm -fv $(@:.o_to_delete=.o)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m""deleted   : $(NAME)""\033[m"

re: fclean all
