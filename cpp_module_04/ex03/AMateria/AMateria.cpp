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

AMateria(std::string const& type) {

	std::cout << "AMateria constructor with type [" << type << "] called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria &other) {

	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria &other) {

	std::cout << "AMateria assignment operator called" << std::endl;

	if (this != &other) {
		
		this->_type = other.getType();
	}
	return *this;
}

std::string const&	getType() const {

	return _type;
}

AMateria::~AMateria() {

	std::cout << "AMateria default constructor called" << std::endl;
}
