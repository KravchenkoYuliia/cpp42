# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 11:19:03 by yukravch          #+#    #+#              #
#    Updated: 2025/10/09 14:23:42 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -std=c++98
FILE = phonebook.cpp

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME):
	c++ $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -f phonebook.o
fclean: clean
	rm -f $(NAME)
re: fclean all
