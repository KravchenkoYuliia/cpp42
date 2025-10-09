# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 11:19:03 by yukravch          #+#    #+#              #
#    Updated: 2025/09/22 12:06:24 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -std=c++98
FILE = megaphone.cpp

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME):
	c++ $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -f megaphone.o
fclean: clean
	rm -f $(NAME)
re: fclean all
