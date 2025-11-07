/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/07 15:42:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavTrap.hpp"

scavTrap::scavTrap() {

	std::cout << "Scav constructor called" << std::endl;
}

scavTrap::scavTrap (const scavTrap& other) {

	*this = other;
}

scavTrap& scavTrap::operator = (const scavTrap& other) {

	if (this != &other)
		this->_name = other.getName();
}


scavTrap::~scavTrap() {

	std::cout << "Scav destructor called" << std::endl;
}
