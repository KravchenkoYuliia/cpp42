/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:54:59 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {

	std::cout << "Dog default constructor called" << std::endl;
	AAnimal::_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog& other ) : AAnimal(other){

	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog&	Dog::operator = ( const Dog& other ) {

	std::cout << "Dog copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_brain = new Brain(other.getBrain());
	return *this;
}

Brain&	Dog::getBrain() const {

	return *_brain;
}

void	Dog::makeSound() const {

	std::cout << "******* Woof *******" << std::endl;
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl;
	delete	_brain;
}


