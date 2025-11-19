/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:00:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 17:00:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp" 
#include "Bureaucrat.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"

int	main() {

	Bureaucrat	b("STEVE", 8);
	std::cout << b << std::endl << std::endl;

	AForm*	f = new ShrubberyCreationForm("home");
	std::cout << std::endl;
}
