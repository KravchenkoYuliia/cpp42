/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 16:48:21 by yukravch         ###   ########.fr       */
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

void	PhoneBook::ft_set_users_data(int i)
{
	PhoneBook::user[PhoneBook::counter].ft_set_data(INDEX, PhoneBook::counter, "");
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

void	PhoneBook::ft_add() {

	PhoneBook::counter++;
	std::string	input[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	
	for (int i = 0; i < 5; i++) {

		std::cout << PROMPT_COLOR << "Put your " << input[i] << ": ";
		std::getline(std::cin, PhoneBook::input);
		if (PhoneBook::input == "")
		{
			i--;
			continue;
		}
		if (PhoneBook::counter == 8)
			PhoneBook::counter = 0;
		PhoneBook::ft_set_users_data(i);
	}

	std::cout << "\033[0m";
}

std::string	PhoneBook::ft_format(int type, int index)
{
	(void)type;
	std::string result = PhoneBook::user[index].ft_get_first_name();
	size_t	len = result.length();

	if (len > 10)
	{
		result.at(9) = '.';
		result = result.substr(0, 10);
	}
	return result;
}

void	PhoneBook::ft_search() {

	for (int i = 0; i < 44; i++){

		std::cout << PIPE_COLOR << '_';
	}
	std::cout << std::endl << '|' << "     Index" << '|' << "First name" << '|' << " Last name" << '|' << "  Nickname" << '|' << std::endl;
	for (int i = 0; i < 8; i++) {

		std::cout << '|'<< "         " << i <<'|'<< ft_format(FIRST_NAME, i) << '|' << std::endl;

	}
	//PhoneBook::user[PhoneBook::counter].ft_get_first_name();
	
}

int	PhoneBook::ft_get_cmd() {

	std::cout << PROMPT_COLOR << "> ";
	std::getline(std::cin, PhoneBook::line);

	if (PhoneBook::line == "")
		return SUCCESS;
	else if (PhoneBook::line == "ADD")
		PhoneBook::ft_add();
	else if (PhoneBook::line == "SEARCH")
		PhoneBook::ft_search();
	else if (PhoneBook::line == "EXIT")
		return EXIT;
	else
		std::cout << "Command doesn't exist" << std::endl;
	std::cout << "\033[0m";
	return SUCCESS;
}

PhoneBook::~PhoneBook() {

	return ;	
}

