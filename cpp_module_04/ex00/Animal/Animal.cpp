/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:49 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:18:31 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {

	std::cout << "Animal default constructor called" << std::endl;
	_type = "general";
}

Animal::Animal( const Animal& other ) {

	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal&		Animal::operator = ( const Animal& other ) {

	std::cout << "Animal copy assignment operator called" << std::endl;
	
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
