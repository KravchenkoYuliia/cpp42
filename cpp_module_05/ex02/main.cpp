/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:00:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/20 13:57:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp" 
#include "Bureaucrat.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"

int	main() {

	Bureaucrat	b("STEVE", 70);
	std::cout << b << std::endl;

	AForm*	f1 = new ShrubberyCreationForm("home");
	std::cout << *f1 << std::endl << std::endl;
	b.signForm(*f1);
	b.executeForm(*f1);
	std::cout << std::endl;
	
	AForm*	f2 = new PresidentialPardonForm("home");
	std::cout << b << std::endl;
	std::cout << *f2 << std::endl << std::endl;
	b.signForm(*f2);
	b.executeForm(*f2);
	std::cout << std::endl;

	AForm*	f3 = new RobotomyRequestForm("home");
	std::cout << b << std::endl;
	std::cout << *f3 << std::endl << std::endl;
	b.signForm(*f3);
	b.executeForm(*f3);
	std::cout << std::endl;
	
	
	delete f1;
	delete f2;
	delete f3;

}
