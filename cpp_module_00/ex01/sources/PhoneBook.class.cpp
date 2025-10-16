/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:42:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

PhoneBook::PhoneBook() {

	PhoneBook::counter = 0;
}

void	PhoneBook::ft_start_prompt() {
	
	std::cout << BLINK << PROMPT_COLOR << "Put your command: "
		<< RESET_ALL
		<< PROMPT_COLOR
		<< UNDERLINE << "ADD"
		<< RESET_ALL
		<< PROMPT_COLOR
		<< ", "
		<< UNDERLINE
		<< "SEARCH"
		<< RESET_ALL
		<< PROMPT_COLOR
		<< " or "
		<< UNDERLINE
		<< "EXIT"
		<< RESET_ALL
		<< std::endl;
}

void	PhoneBook::ft_add() {

	std::string	input[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (int i = 0; i < 5; i++) {

		std::cout << PROMPT_COLOR << "Put your " << input[i] << ": ";
		std::getline(std::cin, PhoneBook::input);
		if (PhoneBook::input == "")
			i--;
	}
	std::cout << "\033[0m";
}

void	PhoneBook::ft_get_cmd() {

	std::cout << PROMPT_COLOR << "> ";
	std::getline(std::cin, PhoneBook::line);

	if (PhoneBook::line == "")
		return ;
	else if (PhoneBook::line == "ADD")
		PhoneBook::ft_add();
	else if (PhoneBook::line == "SEARCH")
		std::cout << "SEARCH";
	else if (PhoneBook::line == "EXIT")
		std::cout << "EXIT";
	else
		std::cout << "Command doesn't exist" << std::endl;
	std::cout << "\033[0m";
}

PhoneBook::~PhoneBook() {

	return ;	
}

