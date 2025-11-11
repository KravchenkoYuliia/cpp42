/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:22:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 11:06:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {

	std::cout << "Diamond default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string inputName) : ClapTrap(inputName + "_clap_name"), ScavTrap(inputName), FragTrap(inputName) {

	this->_name = inputName;
	ClapTrap::_health = 100;
	ClapTrap::_energy = 50;
	ClapTrap::_damage = 30;
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& other) {

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
