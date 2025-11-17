/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:56:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:56:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice&	Ice::operator = (const Ice& other) {

	std::cout << "Ice assignment operator called" << std::endl;
	
	if (this != &other) {
	
	}
	return *this;
}

AMateria*	Ice::clone() const {

	AMateria*	clonedIce = new Ice(*this);

	return clonedIce;
}

Ice::~Ice() {
	
	std::cout << "Ice destructor called" << std::endl;
}
