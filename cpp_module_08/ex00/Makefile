# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 16:44:22 by yukravch          #+#    #+#              #
#    Updated: 2025/11/29 14:28:32 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

all: $(NAME)

HEADER_DEPS = -MMD -MP
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 $(HEADER_DEPS)
FILES = main.cpp

OBJ_DIR = objects
INC_DIR = easyfind.hpp

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
O_DIRS = $(sort $(dir $(OBJ)))


$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

#Dependencies on the header files
DEPS = $(OBJ:.o=.d)
-include $(DEPS)


$(NAME): $(O_DIRS) $(OBJ)
	c++ $(FLAGS) $(FILES) -o $(NAME)

$(O_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(NAME).d
fclean: clean
	rm -f $(NAME)
re: fclean all
