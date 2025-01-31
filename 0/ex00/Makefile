# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 16:14:54 by vperez-f          #+#    #+#              #
#    Updated: 2025/01/27 16:52:55 by vperez-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CFILES = megaphone.cpp

OFILES = $(CFILES:%.cpp=%.o)

CC = c++

FLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fsanitize=leak

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

%.o: %.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OFILES)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re