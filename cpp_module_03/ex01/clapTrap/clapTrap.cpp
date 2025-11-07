/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/07 13:19:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

clapTrap::clapTrap( std::string inputName ) : _name(inputName) {

	_health = 10;
	_energy = 10;
	_damage = 0;

	std::cout << "Constructor for " << _name << " called" << std::endl;
}

clapTrap::clapTrap( const clapTrap& other ) {

	*this = other;
	
	_health = 10;
	_energy = 10;
	_damage = 0;
	
	std::cout << "Copy constructor called" << std::endl;
}

clapTrap&	clapTrap::operator = ( const clapTrap& other ) {

	if (this != &other)
		this->_name = other.getName();
	return *this;
}


std::string	clapTrap::getName() const{

	return _name;
}

void	clapTrap::attack( const std::string& target) {

	std::cout << "ClapTrap [" << _name << "] attacks [" << target << "]";
}

void	clapTrap::takeDamage( unsigned int amount )  {

	std::cout << ", causing " << amount << " points of damage!" << std::endl;
	if (_health > amount)
		_health -= amount;
	else {
		_health = 0;	
		std::cout << _name << " is dead" << std::endl;
	}
	_damage += amount;

}

void	clapTrap::beRepaired( unsigned int amount ) {
	
	if (amount > 10)
		return ;
	if (_energy > amount) {
		_energy -= amount;
		_health += amount;
		std::cout << _name << " is repaired for " << amount << " points" << std::endl;
	}
	else {
		
		std::cout << "[" << _name << "] can't be repaired. Not enough energy" << std::endl << "[" <<  _name << "] is dead" << std::endl;
	}
}

void	clapTrap::printPoints() {

	std::cout << _name << "'s health: [" << _health << "], _energy: [" << _energy << "] and damage: [" << _damage << "]" << std::endl;
}

clapTrap::~clapTrap() {
	
	std::cout << "Destructor for " << _name << " called" << std::endl;
}
