/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 15:26:17 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

clapTrap::clapTrap() {

	std::cout << "Default Clap constructor called" << std::endl;
}

clapTrap::clapTrap( std::string inputName ) : _name(inputName) {

	_health = 10;
	_energy = 10;
	_damage = 0;

	std::cout << "Clap constructor for [" << _name << "] called" << std::endl;
}

clapTrap::clapTrap( std::string inputName, unsigned int inputHealth, unsigned int inputEnergy, unsigned int inputDamage ) : _name(inputName), _health(inputHealth), _energy(inputEnergy), _damage(inputDamage) {
	
	std::cout << "Clap constructor for [" << _name << "] and other data called" << std::endl;
}

clapTrap::clapTrap( const clapTrap& other ) {

	*this = other;
	
	std::cout << "Copy Clap constructor called" << std::endl;
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

	std::cout << "ClapTrap [" << _name << "] attacks [" << target << "], ";
}

void	clapTrap::takeDamage( unsigned int amount )  {

	std::cout << "causing " << amount << " points of damage!" << std::endl;
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
	
	if (_name != "")
		std::cout << "Clap destructor for " << _name << " called" << std::endl;
	else
		std::cout << "Clap destructor called" << std::endl;
}
