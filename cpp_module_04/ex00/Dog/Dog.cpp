/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:24:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:54:01 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() {

	std::cout << "Dog default constructor called" << std::endl;
	Animal::_type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal(other) {

	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator = ( const Dog& other ) {

	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &other)
		Animal::operator = (other);
	return *this;
}
	
void	Dog::makeSound() const {

	std::cout << "******* Woof *******" << std::endl;
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl;
}
