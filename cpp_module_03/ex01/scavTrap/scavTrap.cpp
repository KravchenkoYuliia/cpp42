/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 15:20:53 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavTrap.hpp"

scavTrap::scavTrap() {

	std::cout << "Default scav constructor called" << std::endl;
}

scavTrap::scavTrap(std::string input) : clapTrap(input, 100, 50, 20) {

	std::cout << "Scav constructor for [" << input << "] called" << std::endl;
}

scavTrap::scavTrap (const scavTrap& other) : clapTrap(other){

	std::cout << "Copy Scav constructor called" << std::endl;
}

scavTrap& scavTrap::operator = (const scavTrap& other) {

	if (this != &other)
		clapTrap::operator = (other);
	return *this;
}

void	scavTrap::guardGate() {

	std::cout << "ScavTrap [" << clapTrap::getName() << "] is now in Gate keeper mode" << std::endl;
}

scavTrap::~scavTrap() {

	std::cout << "Scav destructor called" << std::endl;
}
