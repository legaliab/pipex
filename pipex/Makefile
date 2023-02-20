# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 05:20:48 by alabdull          #+#    #+#              #
#    Updated: 2023/02/19 16:47:37 by alabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c execution.c free.c error.c utils.c\

OBJ = $(SRC:.c=.o)

CC = gcc -g3 -fsanitize=address

NAME = pipex

LIB = ./Libft/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

clean:
	@rm -f $(OBJ)
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re