/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:50:36 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 17:08:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::switchcase(int i) {

	switch (i) {

	case 0:
		Harl::debug();
		break ;
	case 1:
		Harl::info();
		break ;
	case 2:
		Harl::warning();
		break ;
	case 3:
		Harl::error();
		break ;
	case 4:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
	
}

void	Harl::complain( std::string level ) {

	bool		alreadyComplained = false;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {

		if (level == levels[i]) {
			alreadyComplained = true;
			while (i < 4) {
				std::cout << "[" << levels[i] << "]" << std::endl;
				Harl::switchcase(i);
				std::cout << std::endl;
				i++;
			}
			break ;
		}
	}
	if (alreadyComplained == false)
		Harl::switchcase(4);
}

void	Harl::debug() {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl;
}

void	Harl::info() {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {

	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
