/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:31:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:54:26 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	std::cout << "WrongAnimal constructor called" << std::endl;
	_type = "general";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {

	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal&		WrongAnimal::operator = ( const WrongAnimal& other ) {

	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	
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
