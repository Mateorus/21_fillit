# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 19:28:39 by gstiedem          #+#    #+#              #
#    Updated: 2018/12/29 14:33:24 by gstiedem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
CFLAGS=-Wall -Werror -Wextra
DBGFLAGS=-g
LIBFLAGS=-L ./libft -lft -I $(INCLUDES)
SRC=./src/*.c
INCLUDES=./libft
LIB_PATH=./libft

.PHONY: $(LIB_PATH)

all: $(NAME)

$(NAME): $(LIB_PATH)
	$(CC) $(CFLAGS) $(SRC) $(LIBFLAGS) -o $(NAME)
clean:
	make -C $(LIB_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
	
$(LIB_PATH):
	make -C $(LIB_PATH)
dbg:
	$(CC) $(CFLAGC) $(DBGFLAGS) $(SRC) $(LIBFLAGS) -o $(NAME)
