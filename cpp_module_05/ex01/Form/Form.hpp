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

class Bureaucrat;
class Form {

public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& other);
	~Form();
	
	Form&	operator = (const Form& other);


	void	tryToSign(Bureaucrat& b);
	void	tryToExec(Bureaucrat& b);


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

private:
	const std::string	_name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExecute;

};

#endif
