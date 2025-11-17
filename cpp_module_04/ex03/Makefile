# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 16:44:22 by yukravch          #+#    #+#              #
#    Updated: 2025/11/13 12:30:13 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

all: $(NAME)

HEADER_DEPS = -MMD -MP
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 $(HEADER_DEPS)
FILES = main.cpp AMateria/AMateria.cpp Character/Character.cpp Cure/Cure.cpp Ice/Ice.cpp MateriaSource/MateriaSource.cpp

OBJ_DIR = objects
INC_DIR = -I AMateria -I Character -I Cure -I Ice -I MateriaSource

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
O_DIRS = $(sort $(dir $(OBJ)))

#Dependencies on the header files
DEPS = $(OBJ:.o=.d)
-include $(DEPS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(FLAGS) $(INC_DIR) -c $< -o $@

$(NAME): $(O_DIRS) $(OBJ)
	c++ $(FLAGS) $(INC_DIR) $(FILES) -o $(NAME)

$(O_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(NAME).d
fclean: clean
	rm -f $(NAME)
re: fclean all
