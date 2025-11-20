/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 12:15:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp" 

class Bureaucrat;
class AForm {

private:
	const std::string	_target;
	const std::string	_name;
	const int		_gradeToSign;
	const int		_gradeToExecute;

public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const std::string target, const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& other);
	virtual ~AForm();
	
	AForm&	operator = (const AForm& other);


	virtual void	beSigned(const Bureaucrat& b) = 0;
	virtual void	execute(const Bureaucrat& executor) const = 0;

	//getters
	const std::string	getTarget() const;
	const std::string	getName() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;


	//exception
	class	GradeTooHighException : public std::exception { const char* what() const throw() { return "grade is too high"; } };
	class	GradeTooLowException : public std::exception { const char* what() const throw() { return "grade is too low"; } };
	class	notSigned : public std::exception { const char* what() const throw() { return "it hasn't been signed"; } };
	class	systemError : public std::exception { const char* what() const throw() { return "of the system error"; } };

};

std::ostream&	operator << (std::ostream &out, const AForm& c);

#endif
