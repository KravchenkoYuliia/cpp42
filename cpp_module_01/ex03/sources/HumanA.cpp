/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:31:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 19:43:08 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string givenName, Weapon& givenWeapon) : weaponA(givenWeapon) {

	HumanA::name = givenName;
	std::cout << "A Constructor called with name: " << givenName << std::endl;
}

void	HumanA::attack() {

	std::cout << this->name << " attacks with their " << this->weaponA.getType() << std::endl;
}

HumanA::~HumanA() {

	std::cout << "A Destructor called" << std::endl;
}
