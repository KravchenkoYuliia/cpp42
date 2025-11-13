/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:45:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap( "", 100, 50, 20 ) {

	std::cout << "Scav default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string input ) : ClapTrap( input, 100, 50, 20 ) {

	std::cout << "Scav constructor for [" << input << "] called" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap& other ) : ClapTrap(other){

	std::cout << "Scav copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = ( const ScavTrap& other ) {

	std::cout << "Scav copy assignement operator called" << std::endl;
	
	if (this != &other)
		ClapTrap::operator = (other);
	return *this;
}

void	ScavTrap::attack(const std::string& target) {

	std::cout << "ScavTrap [" << _name << "] attacks [" << target << "], ";
}

void	ScavTrap::guardGate() {

	std::cout << "ScavTrap [" << ClapTrap::getName() << "] is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {

	std::cout << "Scav destructor called" << std::endl;
}
