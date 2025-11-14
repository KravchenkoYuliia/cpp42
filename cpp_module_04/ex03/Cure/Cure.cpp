/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:14:35 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:14:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {

	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure&	Cure::operator = (const Cure& other) {

	std::cout << "Cure assignment operator called" << std::endl;

	if (this != &other) {

	}
	return *this;
}

Cure::~Cure() {

	std::cout << "Cure destructor called" << std::endl;
}
