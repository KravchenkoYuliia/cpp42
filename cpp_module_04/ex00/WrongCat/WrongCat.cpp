/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:33:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:54:57 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() {

	std::cout << "WrongCat default constructor called" << std::endl;
	WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other) {

	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator = ( const WrongCat& other ) {

	std::cout << "WrongCat copy assignment operator called" << std::endl;

	if (this != &other)
		WrongAnimal::operator = (other);
	return *this;
}

void	WrongCat::makeSound() const {

	std::cout << "******* Meow *******" << std::endl;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destructor called" << std::endl;
}
