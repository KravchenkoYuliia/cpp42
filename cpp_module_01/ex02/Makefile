# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 16:44:22 by yukravch          #+#    #+#              #
#    Updated: 2025/10/24 16:11:10 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = main.cpp

SRC_DIR = sources
OBJ_DIR = objects

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
