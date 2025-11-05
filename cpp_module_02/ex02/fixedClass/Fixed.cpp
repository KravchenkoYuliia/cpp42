/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:46 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/05 14:28:54 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//**********************************************************************************************
//CONSTRUCTOR
Fixed::Fixed(): _value(0) { //DEFAULT 

}

Fixed::Fixed(const int nb) { //INT

	_value = nb * (1 << _nbFractionalBits);
}

Fixed::Fixed(const float nb) { //FLOAT

	_value = roundf(nb * (1 << _nbFractionalBits));
}

Fixed::Fixed(const Fixed& other): _value(0) { //COPY


	*this = other; //assignement operator is used in copy constructor
}

Fixed::~Fixed() { //DESTRUCTOR

}
//***********************************************************************************************

//VALUE MANIPULATION

int	Fixed::toInt() const { //CONVERT TO INT

	return _value / (1 << _nbFractionalBits);
}

float	Fixed::toFloat() const { //CONVERT TO FLOAT

	return (float)_value / (1 << _nbFractionalBits);
}

void	Fixed::setRawBits( int const raw ) { //SETTER OF VALUE

	this->_value = raw;
}

int	Fixed::getRawBits( void ) const { //GETTER OF VALUE

	return this->_value;
}

//**********************************************************************************************

//OPERATORS


std::ostream& operator<<(std::ostream &out, const Fixed& c) { //"<<" STREAM INSERTION OPEATOR

	out << c.toFloat();
	return out;
}

Fixed& Fixed::operator = (const Fixed& other) { //"=" ASSIGNEMENT OPERATOR

	if (this != &other) //check if it's self assignement or not
		this->_value = other.getRawBits();
	return *this;	
}

//ARITHMETIC OPERATORS

Fixed	Fixed::operator * (const Fixed& other) const { //"*"

	Fixed	result;

	result.setRawBits((this->_value * other.getRawBits()) >> _nbFractionalBits);
	return result;
}

Fixed	Fixed::operator / (const Fixed& other) const { //"/"

	Fixed	result;

	if (other._value == 0)
		return result;
	result.setRawBits((this->_value / other.getRawBits()) >> _nbFractionalBits);
	return result;
}

Fixed	Fixed::operator + (const Fixed& other) const { //"+"

	Fixed	result;

	result.setRawBits((this->_value + other.getRawBits()) >> _nbFractionalBits);
	return result;
}

Fixed	Fixed::operator - (const Fixed& other) const { //"-"

	Fixed	result;

	result.setRawBits((this->_value - other.getRawBits()) >> _nbFractionalBits);
	return result;
}


//COMPARISON OPERATORS
bool	Fixed::operator > (const Fixed& other) const { //">"


	return this->_value > other._value;
}

bool	Fixed::operator < (const Fixed& other) const {// "<"


	return this->_value < other._value;
}

bool	Fixed::operator >= (const Fixed& other) const { //">="


	return this->_value >= other._value;
}

bool	Fixed::operator <= (const Fixed& other) const { //"<="


	return this->_value <= other._value;
}

bool	Fixed::operator == (const Fixed& other) const { //"=="


	return this->_value == other._value;
}


bool	Fixed::operator != (const Fixed& other) const { //"!="


	return this->_value != other._value;
}

//INCREMENT AND DECREMENT
	
Fixed&	Fixed::operator++() {

	_value++;
	return *this;
}

Fixed&	Fixed::operator--() {

	_value--;
	return *this;
}


Fixed	Fixed::operator++( int ) {

	Fixed	copy = *this;

	_value++;
	return copy;
}
	
Fixed	Fixed::operator--( int ) {

	Fixed	copy = *this;

	_value--;
	return copy;
}
