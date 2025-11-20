/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:09:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/20 14:09:17 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern&	Intern::operator=(const Intern& other) {

	if (this != &other) {}
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
AForm*	Intern::createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
AForm*	Intern::createPresidential(std::string target) { return new PresidentialPardonForm(target); }


AForm*	Intern::makeForm(std::string name, std::string target) {

	std::cout << "Intern creates " << name << std::endl;

	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(Intern::*ptrToFunctions[3])( std::string ) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	for (int i = 0; i < 3; i++) {
	
		if (name == names[i]) {
			return (this->*ptrToFunctions[i])( target );
		}
	}
	std::cout  << "no" << std::endl;
	return NULL;
}
