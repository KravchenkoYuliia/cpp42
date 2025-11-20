/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:08:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 11:08:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp" 

class AForm;
class Bureaucrat {

private:
	const std::string	_name;
	int			_grade;

public:
	//orthodox form
		Bureaucrat();
		Bureaucrat(const std::string inputName, int inputGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator = (const Bureaucrat& other);

		~Bureaucrat();
	
	//getters
		const std::string	getName() const;
		int			getGrade() const;

	//change _grade
		void	upgradeGrade(int subtract);
		void	downgradeGrade(int add);

	//try to sign/execute
		void    signForm(AForm& f);
		void    executeForm(const AForm& f) const;


	//exception
		class	gradeTooHighException : public std::exception { const char* what() const throw() { return "Error: grade is too high"; } };
		class	gradeTooLowException : public std::exception { const char* what() const throw() { return "Error: grade is too low"; } };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& c);

#endif
