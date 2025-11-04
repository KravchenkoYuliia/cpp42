/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:46 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/04 11:12:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _value(0) { //Copy constructor

	std::cout << "Copy constructor called" << std::endl;

	*this = other; //assignement operator is used in copy constructor
}

Fixed& Fixed::operator = (const Fixed& other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) //check if it's self assignement or not
		this->_value = other.getRawBits();
	return *this;	
}

void	Fixed::setRawBits( int const raw ) {

	this->_value = raw;
}

int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}
