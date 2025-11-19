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

Bureaucrat::Bureaucrat() : _name("") { _grade = 1; }

Bureaucrat::Bureaucrat(const std::string inputName, int inputGrade) : _name(inputName), _grade(inputGrade) {

	if (_grade < 1)
		throw Bureaucrat::gradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::gradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name){ *this = other; }

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) { if (this != &other) { this->_grade = other._grade; }
	return *this; }

Bureaucrat::~Bureaucrat() {}


const std::string	Bureaucrat::getName() const { return _name; }
int			Bureaucrat::getGrade() const { return _grade; }


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

void	Bureaucrat::signForm(AForm& f) {

	try { f.beSigned(*this); }
	catch (std::exception& e) { std::cout << "! " << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl; }
}

void	Bureaucrat::execForm(AForm& f) {

	try { f.beExecuted(*this); }
	catch(std::exception& e) { std::cout << "! " << _name << " couldn't execute " << f.getName() << " because " << e.what() <<     std::endl; }
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& c) {

	const std::string name = c.getName();
	if (name != "")
		out << "+ " << name << ", bureaucrat grade " << c.getGrade();
	else
		out << "+ *Doesn't have a name*" << ", bureaucrat grade " << c.getGrade();
	return out;
}
