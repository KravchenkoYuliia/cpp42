/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 16:57:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

PhoneBook::PhoneBook() {

	PhoneBook::counter = -1;
}

int	PhoneBook::ft_get_cmd() {

	std::cout << PROMPT_COLOR << "> ";
	if (!std::getline(std::cin, PhoneBook::line))
		return EXIT;

	if (PhoneBook::line == "")
		return SUCCESS;
	else if (PhoneBook::line == "ADD") {
		if (PhoneBook::ft_add() == EXIT)
			return EXIT; }
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

