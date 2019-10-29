# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 10:27:21 by qbragard          #+#    #+#              #
#    Updated: 2019/04/29 16:53:24 by lzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_NAME = fillit_algo.c\
		   fillit_checker.c\
		   fillit_placer.c\
		   main.c\
		   ft_sqrt.c\
		   ft_printtab.c\
		   ft_tablen.c\
		   ft_strstrdel.c

SRCS_PATH = ./
OBJS_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIB_PATH = -Llibft
LIB_NAME = -lft

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(LIB_PATH) $(LIB_NAME) $^ -o $@
	@echo "$(NAME) has been successfully created"

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@make clean -C libft

fclean : clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft
	@echo "$(NAME) directory is clean"

re : fclean all
