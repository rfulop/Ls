# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 22:48:41 by rfulop            #+#    #+#              #
#    Updated: 2017/12/11 18:48:11 by rfulop           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

CC = clang
CFLAGS = -g -Wall -Werror -Wextra -Wunused
NAME = ft_ls

SRC_PATH = ./src/
OBJ_PATH = ./obj/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_FILES = main.c \

INC_FILES = ft_ls.h
LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(NAME): $(OBJ_PATH) $(OBJ_EXEC)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@echo "\033[31mObjects files \033[1;31m$(OBJ_FILES)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
