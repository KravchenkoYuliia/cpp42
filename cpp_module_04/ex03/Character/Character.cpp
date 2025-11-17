/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:19:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/17 10:23:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
	
		_slot[i] = NULL;
	}

	for (int i = 0; i < 1000; i++) {

		_leftOnTheFloor[i] = NULL;
	}
}

Character::Character(std::string inputName) : _name(inputName) {

	std::cout << "Character constructor called for [" << inputName << "]" << std::endl;
	for (int i = 0; i < 4; i++) {
	
		_slot[i] = NULL;
	}

	for (int i = 0; i < 1000; i++) {

		_leftOnTheFloor[i] = NULL;
	}
}

Character::Character(const Character& other) {

	std::cout << "Character copy constructor called" << std::endl;
	
	for (int i = 0; i < 4; i++) {

		_slot[i] = NULL;
	}

	for (int i = 0; i < 1000; i++) {

		_leftOnTheFloor[i] = NULL;
	}

	*this = other;
}

Character&	Character::operator=(const Character& other) {

	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {
		
		for (int i = 0; i < 4; i++) {
	

			if (other._slot[i])
				this->_slot[i] = other._slot[i]->clone();
			else
				this->_slot[i] = NULL;
		}
	}
	this->_name = other._name;
	return *this;
}

std::string const&	Character::getName() const {

	return _name;
}

void	Character::equip(AMateria* m) {

	std::cout << "EQUIP" << std::endl;

	for (int i = 0; i < 4; i++) {

		if (!this->_slot[i]) {
		
			_slot[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {

	std::cout << "UNEQUIP from slot [" << idx << "]" << std::endl;
	if (idx < 0 || idx > 3 || !_slot[idx])
		return ;

	if (_slot[idx]) {
	
		for (int i = 0; i < 1000; i++) {
			
			if (!_leftOnTheFloor[i]) {

				_leftOnTheFloor[i] = _slot[idx];
				_slot[idx] = NULL;
				break ;
			}
		}
	}
}

void	Character::use(int idx, ICharacter& target) {

	std::cout << "USE" << std::endl;
	if (idx < 0 || idx > 3 || !_slot[idx]) {
		
		std::cout << "Can't use a slot [" << idx << "]" << std::endl;
		return ;
	}
	if (_slot[idx]) {

		_slot[idx]->use(target);
	}
}

Character::~Character() {

	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {

		if (_slot[i])
			delete _slot[i];
	}

	for (int i = 0; i < 1000; i++) {

		if (_leftOnTheFloor[i])
			delete _leftOnTheFloor[i];
	}
}
