/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:11:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 14:09:13 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string givenName) {

	std::cout << std::endl << "Called HumanB constructor with name[" << givenName << "]" << std::endl;
	name = givenName;
	weaponB = NULL;
}

void	HumanB::setWeapon(Weapon& givenWeapon) {
	

	std::cout << "Setting Weapon of HumanB [" << givenWeapon.getType() << "]" << std::endl;
	
	HumanB::weaponB = &givenWeapon;
}

void	HumanB::attack() {

	if (HumanB::weaponB) {
		std::string	weapon = HumanB::weaponB->getType();
		if (weapon != "")
			std::cout << HumanB::name << " attacks with their weapon[" << weapon << "]" << std::endl;
		else
			std::cout << HumanB::name << " attacks without weapon :(" << std::endl;

	}
	else
		std::cout << HumanB::name << " attacks without weapon :(" << std::endl;
}

HumanB::~HumanB() {

	std::cout << std::endl << "Called Human B destroyer" << std::endl;
}
