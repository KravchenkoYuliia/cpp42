# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 11:19:03 by yukravch          #+#    #+#              #
#    Updated: 2025/10/15 13:17:08 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = main.cpp Contact.class.cpp

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = -I includes

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(FLAGS) $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(INC_DIR) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
