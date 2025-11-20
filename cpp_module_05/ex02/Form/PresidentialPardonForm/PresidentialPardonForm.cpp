/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default target", "PresidentialPardon", 25, 5)  { _isSigned = false; }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, "PresidentialPardon", 25, 5) { _isSigned = false; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) { *this = other; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {

	if (this != &other) { _isSigned = other._isSigned; }
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}



void	PresidentialPardonForm::beSigned(const Bureaucrat& b) {

	if (AForm::getGradeToSign() < b.getGrade()) { throw AForm::GradeTooLowException(); }

	_isSigned = true;
	std::cout << "! " << b.getName() << " has signed the form " << AForm::getName() << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const {

	if (AForm::getGradeToExecute() < b.getGrade()) { throw AForm::GradeTooLowException(); }
	if (_isSigned == false) { throw AForm::notSigned(); }

	std::cout << AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << "! " << b.getName() << " has executed the form " << AForm::getName() << std::endl;
}
