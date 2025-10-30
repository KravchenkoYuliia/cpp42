/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:11:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 12:21:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string givenWeapon) {

	std::cout << "Called Weapon constructor with type of weapon [" << givenWeapon << "]" << std::endl;
	Weapon::setType(givenWeapon);
}

void	Weapon::setType(std::string givenWeapon) {

	std::cout << "Setting type of weapon[" << givenWeapon << "]" << std::endl;
	Weapon::type = givenWeapon;
}

const std::string&	Weapon::getType() const {

	return Weapon::type;
}

Weapon::~Weapon() {

	std::cout << "Called Weapon destroyer" << std::endl << std::endl;
}
