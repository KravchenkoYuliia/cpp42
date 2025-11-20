/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default target", "ShrubberyCreation", 145, 137) { _isSigned = false; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "ShrubberyCreation", 145, 137) { _isSigned = false; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) { *this = other; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {

	if (this != &other) {
		AForm::operator=(other);
		_isSigned = other._isSigned;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}



void	ShrubberyCreationForm::beSigned(const Bureaucrat& b) {

	if (AForm::getGradeToSign() < b.getGrade()) { throw AForm::GradeTooLowException(); }

	_isSigned = true;
	std::cout << "! " << b.getName() << " has signed the form " << AForm::getName() << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const {
	
	if (AForm::getGradeToExecute() < b.getGrade()) { throw AForm::GradeTooLowException(); }
	if (_isSigned == false) { throw AForm::notSigned(); }


	std::string	fileName = AForm::getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file) { throw AForm::systemError(); }

	file << "                ,@@@@@@@,                         " << std::endl
	    <<  "        ,,,.   ,@@@@@@/@@,  .oo8888o.             " << std::endl
	    <<  "     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o           " << std::endl
	    <<  "    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'        " << std::endl
	    <<  "    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'         " << std::endl
            <<  "    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'          " << std::endl
	    <<  "    `&%\\ ` /%&'    |.|        \\ '|8'            " << std::endl
	    <<  "        |o|        | |         | |                " << std::endl
	    <<  "        |.|        | |         | |                " << std::endl
	    <<  "     \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ " << std::endl;
	file.close();
	std::cout << "! " << b.getName() << " has executed the form " << AForm::getName() << std::endl;
}
