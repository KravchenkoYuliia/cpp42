/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:00:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/20 15:00:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp" 
#include "Bureaucrat.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	Intern	someRandomIntern;
	AForm*	f;
	
	Bureaucrat	b("STEVE", 70);
	std::cout << b << std::endl;

	f = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *f << std::endl << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	std::cout << std::endl;
	delete f;
	
	f = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *f << std::endl << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	std::cout << std::endl;
	delete f;

	f = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *f << std::endl << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	std::cout << std::endl;
	delete f;
		
}
