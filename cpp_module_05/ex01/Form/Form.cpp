/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 16:45:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _gradeToSign(1), _gradeToExecute(1) {

	std::cout << "       Form default constructor" << std::endl;
	_isSigned = false;
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {

	std::cout << "       Form copy constructor" << std::endl;
	*this = other;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	std::cout << "       Form constructor for [" << _name << "] with grades " << _gradeToSign << " and " << _gradeToExecute << std::endl;
	
}

Form&	Form::operator=(const Form& other) {

	std::cout << "       Form assignment operator" << std::endl;
	if (this != &other) {

		_isSigned = other._isSigned;
	}
	return *this;
}


void	Form::tryToSign(Bureaucrat& b) {

	if (_gradeToSign < b._grade) {
		std::cout << b.getName << " couldn't sign " << _name << "because " << std::endl;
		throw Form::GradeTooLowException();
	}

	std::cout << b.getName << " signed " << _name << std::endl;
	_isSigned = true;
}

void	Form::tryToExec(Bureaucrat& b) {

	if (_gradeToExecute < b._grade) {
		std::cout << b.getName << " couldn't execute " << _name << "because " << std::endl;
		throw Form::GradeTooLowException();
	}
	if (_isSigned == false) {
		std::cout << b.getName << " couldn't execute " << _name << "because " << std::endl;
		throw Form::notSigned();
	}
}

Form::~Form() {

	std::cout << "       Form destructor" << std::endl;
}
