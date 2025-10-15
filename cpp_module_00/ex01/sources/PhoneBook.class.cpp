/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 15:36:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

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

void	PhoneBook::ft_get_cmd() {

	std::cout << PROMPT_COLOR << "> ";
	std::getline(std::cin, PhoneBook::line);
	std::cout << MAGENTA_BACKGROUND << "Your cmd is " << PhoneBook::line << std::endl;
	std::cout << "\033[0m";
	(void)PhoneBook::counter;
}
