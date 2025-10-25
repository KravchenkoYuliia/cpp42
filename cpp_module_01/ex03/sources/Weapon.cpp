/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:31:58 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 18:34:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string givenWeapon) {

	std::cout << "Constructor called with weapon: " << givenWeapon << std::endl;
}

Weapon::~Weapon() {

	std::cout << "Destructor for Weapon called" << std::endl;
}
