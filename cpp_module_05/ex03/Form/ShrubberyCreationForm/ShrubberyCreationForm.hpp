/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp" 

class	Bureaucrat;
class	ShrubberyCreationForm : public virtual AForm{

private:
	bool	_isSigned;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator = (const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void	beSigned(const Bureaucrat& b);
	void	execute(const Bureaucrat& b) const;
};

#endif
