/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:31:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:42:50 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	_type = "general";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {

	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&		WrongAnimal::operator = ( const WrongAnimal& other ) {

	if (this != &other)
		this->_type = other.getType();
	return *this;
}

std::string	WrongAnimal::getType() const {

	return _type;
}

void	WrongAnimal::makeSound() const {

	std::cout << "******* Random animal [🐮 Cow: moo] *******" << std::endl;
}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal destructor called" << std::endl;
}
