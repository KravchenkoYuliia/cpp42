/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:46 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 17:37:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0), _nbFractionalBits(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed(const Fixed &copyFixed): _value(0), _nbFractionalBits(0) {

	std::cout << "Copy constructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw ) {


}

int	Fixed::getRawBits( int const raw ) const {

	std::cout << "getRawBits member function called" << std::endl;
}

Fixed::~Fixed(): {

	std::cout << "Destructor called" << std::endl;
}
