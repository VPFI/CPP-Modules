# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 20:19:37 by vpf               #+#    #+#              #
#    Updated: 2025/01/31 20:07:00 by vperez-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brains

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJ_DIR = obj/

OBJ = $(SRC:%.cpp=$(OBJ_DIR)%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fsanitize=leak

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm $(NAME)

fcelan: clean
	@rm $(NAME)
