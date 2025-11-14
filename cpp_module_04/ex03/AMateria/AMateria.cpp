/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:06:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:06:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {

	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {

	std::cout << "AMateria constructor with type [" << type << "] called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {

	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria &other) {

	std::cout << "AMateria assignment operator called" << std::endl;

	if (this != &other) {
			
	}
	return *this;
}

const std::string&	AMateria::getType() const {

	return _type;
}

void	AMateria::use(ICharacter& target) {

	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "Wrong type" << std::endl;
}

AMateria::~AMateria() {


	std::cout << "AMateria default constructor called" << std::endl;
}
