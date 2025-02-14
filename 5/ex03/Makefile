# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 20:19:37 by vpf               #+#    #+#              #
#    Updated: 2025/02/14 21:03:47 by vpf              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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
	@rm *_shrubbery

fcelan: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
