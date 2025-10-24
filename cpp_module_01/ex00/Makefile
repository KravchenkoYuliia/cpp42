# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 16:44:22 by yukravch          #+#    #+#              #
#    Updated: 2025/10/24 15:10:58 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

all: $(NAME)

FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = -I includes

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
DEPS = $(OBJ:.o=.d)
-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(FLAGS) $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(INC_DIR) $(SRC) -o $(NAME)

clean:
	rm -fr $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
