/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 16:11:12 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

PhoneBook::PhoneBook() {

	PhoneBook::counter = -1;
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
	
	PhoneBook::user[PhoneBook::counter].ft_set_data(INDEX, PhoneBook::counter, "");
	for (int data = 0; data < 5; data++) {

		std::cout << PROMPT_COLOR << "Put your " << input[data] << ": ";
		std::getline(std::cin, PhoneBook::input);
		if (PhoneBook::input == "")
		{
			data--;
			continue;
		}
		if (PhoneBook::counter == 8)
			PhoneBook::counter = 0;
		PhoneBook::ft_set_users_data(data);
	}

	std::cout << "\033[0m";
}

std::string	PhoneBook::ft_format(int type, int index)
{
	std::string	result;

	if (type == FIRST_NAME)
		result = PhoneBook::user[index].ft_get_first_name();
	else if (type == LAST_NAME)
		result = PhoneBook::user[index].ft_get_last_name();
	else if (type == NICKNAME)
		result = PhoneBook::user[index].ft_get_nickname();
	
	if (result == "")
		result = "          ";
	size_t	len = result.length();

	if (len > 10)
	{
		result.at(9) = '.';
		result = result.substr(0, 10);
	}
	else if (len < 10)
	{
		result = std::string(10 - len, ' ') + result;
	}
	return result;
}

void	PhoneBook::ft_search() {

	PhoneBook::ft_horizontal_line();
	std::cout << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "     Index"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "First name"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << " Last name"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "  Nickname"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< RESET_ALL << std::endl;

	PhoneBook::ft_horizontal_line();
	for (int i = 0; i < 8; i++) {

		std::cout << PIPE_COLOR << '|'
			<< USER_DATA_COLOR << "         " << i + 1
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(FIRST_NAME, i)
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(LAST_NAME, i)
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(NICKNAME, i)
			<< PIPE_COLOR << '|'
			<< RESET_ALL << std::endl;

	}

	PhoneBook::ft_horizontal_line();
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

