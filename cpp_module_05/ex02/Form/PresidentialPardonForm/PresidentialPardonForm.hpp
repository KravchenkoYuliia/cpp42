/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:02:25 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 13:02:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp" 

class PresidentialPardonForm : public virtual AForm {

private:
	bool	_isSigned;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator = (const PresidentialPardonForm& other);

	~PresidentialPardonForm();

	void	beSigned(const Bureaucrat& b);
	void	execute(const Bureaucrat& b) const;
};

#endif
