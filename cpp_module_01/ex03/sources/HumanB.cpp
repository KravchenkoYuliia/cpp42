/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:31:34 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 19:47:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string givenName) {

	HumanB::name = givenName;
	HumanB::weaponB = NULL;
	std::cout << "B Constructor called with name: " << givenName << std::endl;
}

void	HumanB::setWeapon(Weapon* givenWeapon) {


	std::cout << "Setting a weapon for B" << std::endl;
}

void	HumanB::attack() {

	std::cout << "B attacks" << std::endl;//this->name << " attacks with their " << this->weaponA.getType() << std::endl;
}

HumanA::~HumanB() {

	std::cout << "B Destructor called" << std::endl;
}
