/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 16:45:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp" 

class Bureaucrat;
class Form {

private:
	const std::string	_name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExecute;

public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& other);
	~Form();
	
	Form&	operator = (const Form& other);


	void	beSigned(Bureaucrat& b);
	void	beExecuted(Bureaucrat& b);


	//getters
	const std::string	getName() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;

	class GradeTooHighException : public std::exception {
	
		const char* what() const throw() {
		
			return "grade is too high";
		}
	};
	
	class GradeTooLowException : public std::exception {
	
		const char* what() const throw() {
		
			return "grade is too low";
		}
	};
	
	class notSigned : public std::exception {

		const char* what() const throw() {
		
			return "it hasn't been signed";
		}
	};
};

std::ostream&	operator << (std::ostream &out, const Form& c);

#endif
