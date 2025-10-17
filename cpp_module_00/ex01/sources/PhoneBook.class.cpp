/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 18:41:50 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

PhoneBook::PhoneBook() {

	PhoneBook::counter = -1;
	PhoneBook::nb_of_users = 0;
	PhoneBook::empty = true;
}

int	PhoneBook::ft_get_cmd() {

	std::cout << PROMPT_COLOR << "> ";
	if (!std::getline(std::cin, PhoneBook::line))
		return EXIT;

	if (PhoneBook::line == "ADD") {
		if (PhoneBook::ft_add() == EXIT)
			return EXIT; }
	else if (PhoneBook::line == "SEARCH") {
		if (PhoneBook::ft_search() == EXIT)
			return EXIT; }
	else if (PhoneBook::line == "EXIT")
		return EXIT;
	else
		return SUCCESS;
	
	std::cout << "\033[0m";
	return SUCCESS;
}

PhoneBook::~PhoneBook() {

	return ;
}

