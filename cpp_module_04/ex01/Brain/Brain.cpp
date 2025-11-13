/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:45:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {

	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain& other ) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain&	Brain::operator = ( const Brain& other ) {

	std::cout << "Brain copy assignment operator called" << std::endl;
	
	if (this != &other) {

		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other.getIdea(i);
		}
	}
	return *this;
}

void	Brain::setIdea(std::string idea, int i) {

	this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const {

	return _ideas[i];
}


Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl;
}


