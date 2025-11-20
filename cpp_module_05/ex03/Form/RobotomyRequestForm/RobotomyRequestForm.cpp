/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default target", "RobotomyRequest", 72, 45) { _isSigned = false; }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, "RobotomyRequest", 72, 45) { _isSigned = false; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) { *this = other;}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {

	if (this != &other) { _isSigned = other._isSigned; }
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void	RobotomyRequestForm::beSigned(const Bureaucrat& b) {

	if (AForm::getGradeToSign() < b.getGrade()) { throw AForm::GradeTooLowException(); }

	_isSigned = true;
	std::cout << "! " << b.getName() << " has signed the form " << AForm::getName() << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const {

	if (AForm::getGradeToExecute() < b.getGrade()) { throw AForm::GradeTooLowException(); }
	if (_isSigned == false) { throw AForm::notSigned(); }

	std::cout << "**some drilling noises**" << std::endl << AForm::getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
	std::cout << "! " << b.getName() << " has executed the form " << AForm::getName() << std::endl;
}

