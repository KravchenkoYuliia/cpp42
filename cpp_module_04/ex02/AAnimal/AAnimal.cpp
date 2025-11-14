/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:49 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:40:58 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {

	std::cout << "AAnimal constructor called" << std::endl;
	_type = "general";
}

AAnimal::AAnimal( const AAnimal& other ) {

	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal&		AAnimal::operator = ( const AAnimal& other ) {

	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

std::string	AAnimal::getType() const {

	return _type;
}

AAnimal::~AAnimal() {

	std::cout << "AAnimal destructor called" << std::endl;
}
