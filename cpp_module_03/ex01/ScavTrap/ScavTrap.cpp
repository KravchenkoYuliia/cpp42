/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 15:44:03 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {

	std::cout << "Default scav constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string input) : ClapTrap(input, 100, 50, 20) {

	std::cout << "Scav constructor for [" << input << "] called" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& other) : ClapTrap(other){

	std::cout << "Copy Scav constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other) {

	if (this != &other)
		ClapTrap::operator = (other);
	return *this;
}

void	ScavTrap::guardGate() {

	std::cout << "ScavTrap [" << ClapTrap::getName() << "] is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {

	std::cout << "Scav destructor called" << std::endl;
}
