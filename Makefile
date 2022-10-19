# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 11:25:38 by aruiz-mo          #+#    #+#              #
#    Updated: 2022/09/01 16:28:53 by aruiz-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = mlx

LIB = -Lmlx -lmlx -lm

FRW = -framework OpenGL -framework Appkit

OBJ = main.o fractals.o utils.o utils_2.o

NAME = fractol

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C $(INC)
	$(CC) $(OBJ) $(LIB) $(FRW) -o $(NAME)

clean:
	@rm -f $(OBJ)
	$(MAKE) -C $(INC) clean

fclean: clean
	@rm -f $(NAME)

re: fclean
	$(MAKE)

bonus: $(NAME)

.PHONY: clean fclean re