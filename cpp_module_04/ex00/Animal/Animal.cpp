/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:49 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:15:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {

	_type = "general";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& other ) {

	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&		Animal::operator = ( const Animal& other ) {

	if (this != &other)
		this->_type = other.getType();
	return *this;
}

std::string	Animal::getType() const {

	return _type;
}

Animal::~Animal() {

	std::cout << "Animal destructor called" << std::endl;
}
