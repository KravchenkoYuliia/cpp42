/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:51:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {

	std::cout << "Cat default constructor called" << std::endl;
	AAnimal::_type = "Cat";
	_brain = new Brain();
}

Cat::Cat( const Cat& other ) : AAnimal(other){

	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat&	Cat::operator = ( const Cat& other ) {

	std::cout << "Cat copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_brain = new Brain(other.getBrain());
	return *this;
}

Brain&	Cat::getBrain() const {

	return *_brain;
}

void	Cat::makeSound() const {

	std::cout << "******* Meow *******" << std::endl;
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
	delete	_brain;
}


