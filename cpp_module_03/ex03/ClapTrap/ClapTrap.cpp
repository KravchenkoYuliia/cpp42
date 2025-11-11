/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 11:36:13 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	std::cout << "Default Clap constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string inputName ) : _name(inputName) {

	_health = 10;
	_energy = 10;
	_damage = 0;

	std::cout << "Clap constructor for [" << _name << "] called" << std::endl;
}

ClapTrap::ClapTrap( std::string inputName, unsigned int inputHealth, unsigned int inputEnergy, unsigned int inputDamage ) : _name(inputName), _health(inputHealth), _energy(inputEnergy), _damage(inputDamage) {
	
	std::cout << "Clap constructor for [" << _name << "] and other data called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) {

	*this = other;
	
	std::cout << "Clap copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator = ( const ClapTrap& other ) {

	if (this != &other)
		this->_name = other.getName();
	return *this;
}


std::string	ClapTrap::getName() const{

	return _name;
}

void	ClapTrap::attack( const std::string& target) {

	std::cout << "ClapTrap [" << _name << "] attacks [" << target << "], ";
}

void	ClapTrap::takeDamage( unsigned int amount )  {

	std::cout << "causing " << amount << " points of damage!" << std::endl;
	if (_health > amount)
		_health -= amount;
	else {
		_health = 0;	
		std::cout << "ClapTrap [" <<  _name << "]: by guys 🙌" << std::endl;
		std::cout << "ClapTrap [" << _name << "] is dead" << std::endl;
	}
	_damage += amount;

}

void	ClapTrap::beRepaired( unsigned int amount ) {
	
	if (amount > 10)
		return ;
	if (_energy > amount) {
		_energy -= amount;
		_health += amount;
		std::cout << "ClapTrap [" <<  _name << "] is repaired for " << amount << " points" << std::endl;
	}
	else {
		
		std::cout << "ClapTrap [" << _name << "] can't be repaired. Not enough energy" << std::endl << "[" <<  _name << "] is dead" << std::endl;
		std::cout << "ClapTrap [" <<  _name << "]: by guys 🙌" << std::endl;
	}
}

void	ClapTrap::printPoints() {

	std::cout << _name << "'s health: [" << _health << "], _energy: [" << _energy << "] and damage: [" << _damage << "]" << std::endl;
}

ClapTrap::~ClapTrap() {
	
	if (_name != "")
		std::cout << "Clap destructor for " << _name << " called" << std::endl;
	else
		std::cout << "Clap destructor called" << std::endl;
}
