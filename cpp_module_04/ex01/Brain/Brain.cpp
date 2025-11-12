/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 12:18:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {

	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain& other ) {

	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain&	Brain::operator = ( const Brain& other ) {

	if (this != &other) {

		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other.getIdeas(i);
		}
	}
	return *this;
}

std::string	Brain::getIdeas(int i) const {

	return _ideas[i];	
}

Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl;
}


