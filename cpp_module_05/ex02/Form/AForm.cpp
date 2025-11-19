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

#include "AForm.hpp"

//constructors
AForm::AForm() : _name("default name"), _gradeToSign(1), _gradeToExecute(1) { _isSigned = false; }


AForm::AForm(const std::string target, const std::string name, const int gradeToSign, const int gradeToExecute) : _target(target), _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}


AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}


AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) { *this = other; }


AForm&	AForm::operator=(const AForm& other) {

	if (this != &other) { _isSigned = other._isSigned; }
	return *this;
}

AForm::~AForm() {}


//getters
const std::string	AForm::getTarget() const { return _target; };
const std::string	AForm::getName() const { return _name; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExecute() const { return _gradeToExecute; }


void	AForm::beSigned(Bureaucrat& b) {

	if (_gradeToSign < b.getGrade()) { throw AForm::GradeTooLowException(); }

	std::cout << "! " << b.getName() << " signed " << _name << std::endl;
	_isSigned = true;
}

void	AForm::beExecuted(Bureaucrat& b) {

	if (_gradeToExecute < b.getGrade()) { throw AForm::GradeTooLowException(); }
	if (_isSigned == false) { throw AForm::notSigned(); }

	std::cout << "! " << b.getName() << " executed " << _name << std::endl;
}

std::ostream&	operator << (std::ostream &out, const AForm& c) { out << "+ " << "AForm: name[" << c.getName() << "], grade to be signed[" << c.getGradeToSign() << "]" << " grade to be executed[" << c.getGradeToExecute() << "]";
	return out; }
