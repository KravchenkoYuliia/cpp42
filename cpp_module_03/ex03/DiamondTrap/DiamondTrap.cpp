/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:22:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 16:31:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {

	std::cout << "Diamond default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string inputName) : _name(inputName) {

	std::cout << "Diamond constructor called" << std::endl;

	std::string	suffix = "_clap_name";
	ClapTrap::_name += suffix;
}

DiamondTrap::~DiamondTrap() {

	std::cout << "Diamond destructor called" << std::endl;
}
