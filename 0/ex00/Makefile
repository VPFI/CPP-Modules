# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 16:14:54 by vperez-f          #+#    #+#              #
#    Updated: 2025/02/01 17:36:18 by vpf              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

OBJ_DIR = obj/

OBJ = $(SRC:%.cpp=$(OBJ_DIR)%.o)

DEP	= $(OBJ:%.o=%.d)

DEPFLAGS = -MMD -MP

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fsanitize=leak

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm $(NAME)

fcelan: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)