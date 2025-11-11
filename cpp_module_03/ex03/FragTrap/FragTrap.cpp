/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:48:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 10:35:45 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {

	std::cout << "Default Frag constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	
	std::cout << "Copy Frag constructor called" << std::endl;
}

FragTrap& 	FragTrap::operator = (const FragTrap& other) {

	if (this != &other)
		ClapTrap::operator = (other);
	return *this;
}

FragTrap::FragTrap(std::string input) : ClapTrap(input, 100, 100, 30) {

        std::cout << "Frag constructor for [" << input << "] called" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {

	std::cout << ClapTrap::getName() << ": hi guys 🙌" << std::endl;
}

FragTrap::~FragTrap() {

	std::cout << "Frag destructor called" << std::endl;
}
