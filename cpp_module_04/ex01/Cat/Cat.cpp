/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:14:53 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() {

	Animal::_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other) {

	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator = ( const Cat& other ) {

	if (this != &other)
		Animal::operator = (other);
	return *this;
}

void	Cat::makeSound() const {

	std::cout << "******* Meow *******" << std::endl;
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
}


