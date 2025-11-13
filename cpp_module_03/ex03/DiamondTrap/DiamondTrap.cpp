/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:22:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:50:06 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {

	std::cout << "Diamond default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string inputName) : ClapTrap(inputName + "_clap_name"), ScavTrap(inputName), FragTrap(inputName) {

	std::cout << "Diamond constructor called" << std::endl;
	
	this->_name = inputName;
	
	ClapTrap::_hit = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_damage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other) {

	std::cout << "Diamond copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& other) {

	std::cout << "Diamond copy assignement operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator = (other);
	return *this;
}

void	DiamondTrap::whoAmI() {

	std::cout << "Diamond name: [" << this->_name << "]" << std::endl;
	std::cout << "Clap name: [" << ClapTrap::getName() << "]" << std::endl;
}

DiamondTrap::~DiamondTrap() {

	std::cout << "Diamond destructor called" << std::endl;
}
