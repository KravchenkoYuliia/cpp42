/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:09:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/20 14:48:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp" 

#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern& other);
	Intern&	operator = (const Intern& other);

	~Intern();
	
	AForm*	makeForm(std::string name, std::string target);

	AForm*	createShrubbery(std::string target);
	AForm*	createRobotomy(std::string target);
	AForm*	createPresidential(std::string target);
};

#endif
