/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:15:21 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/17 10:15:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

	std::cout << "MateriaSource default constructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
	
		this->_slot[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other ) {

	*this = other;
}

void	MateriaSource::learnMateria(AMateria* someMateria) {

	if (someMateria->getType() != "ice" && someMateria->getType() != "cure")
		return ;
	for (int i = 0; i < 4; i++) {

		if (!this->_slot[i]) {
		
			this->_slot[i] = someMateria;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria( const std::string& type ) {

	for (int i = 0; i < 4; i++) {

		if (_slot[i]->getType() == type)
			return _slot[i];
	}

	return NULL;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {

	if (this != &other) {

		for (int i = 0; i < 4; i++) {
		
			if (other._slot[i])
				this->_slot[i] = other._slot[i]->clone();
			else
				this->_slot[i] = NULL;

		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {

	std::cout << "MateriaSource destructor called" << std::endl;
}
