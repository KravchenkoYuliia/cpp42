/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:48:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:49:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {

	std::cout << "Frag default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	
	std::cout << "Frag copy constructor called" << std::endl;
}

FragTrap& 	FragTrap::operator = (const FragTrap& other) {

	std::cout << "Frag copy assignement operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator = (other);
	return *this;
}

FragTrap::FragTrap(std::string input) : ClapTrap(input, 100, 100, 30) {

        std::cout << "Frag constructor for [" << input << "] called" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {

	std::cout << "FragTrap [" << ClapTrap::getName() << "] : hi guys 🙌" << std::endl;
}

FragTrap::~FragTrap() {

	std::cout << "Frag destructor called" << std::endl;
}
