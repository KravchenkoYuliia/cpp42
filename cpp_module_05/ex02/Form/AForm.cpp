/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 12:15:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAForm.hpp"

AForm::AForm() : _name(""), _gradeToSign(1), _gradeToExecute(1) {

	std::cout << "       AForm default constructor" << std::endl;
	_isSigned = false;
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {

	std::cout << "       AForm copy constructor" << std::endl;
	*this = other;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	std::cout << "       AForm constructor for [" << _name << "] with grades " << _gradeToSign << " and " << _gradeToExecute << std::endl;
	
}

AForm&	AForm::operator=(const AForm& other) {

	std::cout << "       AForm assignment operator" << std::endl;
	if (this != &other) {

		_isSigned = other._isSigned;
	}
	return *this;
}

//getters
const std::string	AForm::getName() const {

	return _name;
}

int	AForm::getGradeToSign() const {

	return _gradeToSign;
}

int	AForm::getGradeToExecute() const {

	return _gradeToExecute;
}
//


void	AForm::beSigned(Bureaucrat& b) {

	if (_gradeToSign < b.getGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "! " << b.getName() << " signed " << _name << std::endl;
	_isSigned = true;
}

void	AForm::beExecuted(Bureaucrat& b) {

	if (_gradeToExecute < b.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (_isSigned == false) {
		throw AForm::notSigned();
	}
	std::cout << "! " << b.getName() << " executed " << _name << std::endl;
}

std::ostream&	operator << (std::ostream &out, const AForm& c) {

	
	out << "+ " << "AForm: name[" << c.getName() << "], grade to be signed[" << c.getGradeToSign() << "]" << " grade to be executed[" << c.getGradeToExecute() << "]";

	return out;
}

AForm::~AForm() {

	std::cout << "       AForm destructor" << std::endl;
}
