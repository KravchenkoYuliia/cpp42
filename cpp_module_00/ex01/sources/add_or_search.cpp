/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_or_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:55 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 18:26:40 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"



int	PhoneBook::ft_search() {

	if (PhoneBook::empty) {
		std::cout << "No users have been added" << std::endl;
		return SUCCESS;
	}
	PhoneBook::ft_write_horizontal_line();
	PhoneBook::ft_write_table_headlines();
	PhoneBook::ft_write_horizontal_line();
	PhoneBook::ft_write_users_data();
	PhoneBook::ft_write_horizontal_line();

	int		get_index = 0;
	std::string	line;
	while (1) {
		
		std::cout << PROMPT_COLOR << "Choose one index " << BLINK << "> " << RESET_ALL << PROMPT_COLOR;
		if (!std::getline(std::cin, line))
			return EXIT;
		get_index = std::atoi(line.c_str());
		if (get_index < 1 || get_index > PhoneBook::nb_of_users) {
			std::cout << "Index doesn't exist" << std::endl;
			continue ;
		}
		break ;
	}
	PhoneBook::ft_write_full_user_data(get_index);
	return SUCCESS;
}

void	PhoneBook::ft_set_users_data(int i)
{
	if (i == 0)
		PhoneBook::user[PhoneBook::counter].ft_set_data(FIRST_NAME, 0, PhoneBook::input);
	if (i == 1)
		PhoneBook::user[PhoneBook::counter].ft_set_data(LAST_NAME, 0, PhoneBook::input);
	if (i == 2)
		PhoneBook::user[PhoneBook::counter].ft_set_data(NICKNAME, 0, PhoneBook::input);
	if (i == 3)
		PhoneBook::user[PhoneBook::counter].ft_set_data(PHONE, 0, PhoneBook::input);
	if (i == 4)
		PhoneBook::user[PhoneBook::counter].ft_set_data(SECRET, 0, PhoneBook::input);
}

int	PhoneBook::ft_add() {

	PhoneBook::counter++;
	PhoneBook::empty = false;
	if (PhoneBook::nb_of_users < 8)
		PhoneBook::nb_of_users++;
	std::string	input[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	
	PhoneBook::user[PhoneBook::counter].ft_set_data(INDEX, PhoneBook::counter, "");
	for (int data = 0; data < 5; data++) {

		std::cout << PROMPT_COLOR << "Put your " << input[data] << ": ";
		
		if (!std::getline(std::cin, PhoneBook::input))
			return EXIT;

		if (PhoneBook::input == "")
		{
			std::cin.clear();
			data--;
			continue;
		}
		if (PhoneBook::counter == 8)
			PhoneBook::counter = 0;
		PhoneBook::ft_set_users_data(data);
	}

	std::cout << "\033[0m";
	return SUCCESS;
}
