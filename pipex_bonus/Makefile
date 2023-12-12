# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 05:20:48 by alabdull          #+#    #+#              #
#    Updated: 2023/12/11 18:00:55 by alabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c execution.c free.c error.c utils.c\

OBJ = $(SRC:.c=.o)

CC = gcc -g3 #-fsanitize=address

NAME = pipex

LIB = ./Libft/libft.a

GNL = ./Libft/get_next_line/getnextline.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(GNL) -o $(NAME) 

clean:
	@rm -f $(OBJ)
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re