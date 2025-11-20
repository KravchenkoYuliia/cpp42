/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp" 

class RobotomyRequestForm : public virtual AForm {

private:
	bool	_isSigned;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator = (const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	void	beSigned(const Bureaucrat& b);
	void	execute(const Bureaucrat& b) const;
};

#endif
