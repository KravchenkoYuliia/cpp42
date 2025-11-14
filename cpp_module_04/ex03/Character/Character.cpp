/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:19:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 13:19:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character& other) {

	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character&	Character::operator=(const Character& other) {

	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {

	}
	return *this;
}

std::string const&	Character::getName() const {

	return _name;
}

void	Character::equip(AMateria* m) {

	(void)m;
}

void	Character::unequip(int idx) {

	if (idx < 0 || idx > 3)
		return ;
}

void	Character::use(int idx, ICharacter& target) {

	if (idx < 0 || idx > 3)
		return ;
	if (_slot[idx]) {

		_slot[idx]->use(target);
	}
}

Character::~Character() {

	std::cout << "Character destructor called" << std::endl;
}
