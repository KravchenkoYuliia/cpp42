/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:11:07 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 12:20:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string givenName, Weapon& givenWeapon) : weaponA(givenWeapon) {

	std::cout << std::endl << "Called HumanA constructor with name[" << givenName << "] and Weapon Class" << std::endl;
	name = givenName;
}

void	HumanA::attack() {

	std::cout << HumanA::name << " attacks with their weapon[" << HumanA::weaponA.getType() << "]" << std::endl;
}

HumanA::~HumanA() {

	std::cout << std::endl << "Called Human A destroyer" << std::endl;
}
