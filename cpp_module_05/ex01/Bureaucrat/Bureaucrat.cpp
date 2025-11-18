/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:08:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 11:08:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"   

Bureaucrat::Bureaucrat() : _name("") {

	std::cout << "_____Bureaucrat default constructor" << std::endl;
	_grade = 1;
}

Bureaucrat::Bureaucrat(const std::string inputName, int inputGrade) : _name(inputName), _grade(inputGrade) {

	std::cout << "_____Bureaucrat constructor with name [" << inputName << "] and grade[" << inputGrade << "]" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::gradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::gradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name){

	std::cout << "_____Bureaucrat copy constructor" << std::endl;
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	
	std::cout << "_____Bureaucrat operator assignment" << std::endl;

	if (this != &other) {
	
		this->_grade = other._grade;
	}
	return *this;
}

const std::string	Bureaucrat::getName() const {

	return _name;
}

int	Bureaucrat::getGrade() const {

	return _grade;
}

void	Bureaucrat::downgradeGrade(int add) {

	if (_grade + add > 150)
		throw Bureaucrat::gradeTooLowException();
	_grade += add;
}

void	Bureaucrat::upgradeGrade(int subtract) {

	if (_grade - subtract < 1)
		throw Bureaucrat::gradeTooHighException();
	_grade -= subtract;
}

void	Bureaucrat::signForm(Form& f){

	f.tryToSign(*this);
}

void	Bureaucrat::execForm(Form& f) {

	f.tryToExec(*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& c) {

	const std::string name = c.getName();
	if (name != "")
		out << "+ " << name << ", bureaucrat grade " << c.getGrade();
	else
		out << "+ *Doesn't have a name*" << ", bureaucrat grade " << c.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat() {

	std::cout << "_____Bureaucrat destructor" << std::endl;
}
