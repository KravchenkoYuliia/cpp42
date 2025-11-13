/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 10:42:30 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	std::cout << "Clap default constructor called" << std::endl;
	
	_hit = 10;
	_energy = 10;
	_damage = 0;

}

ClapTrap::ClapTrap( std::string inputName ) : _name( inputName ) {

	std::cout << "Clap constructor for " << _name << " called" << std::endl;
	
	_hit = 10;
	_energy = 10;
	_damage = 0;

}

ClapTrap::ClapTrap( const ClapTrap& other ) {

	std::cout << "Clap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator = ( const ClapTrap& other ) {

	std::cout << "Clap copy assignement operator called" << std::endl;
	if ( this != &other ) {

		this->_name = other.getName();
		this->_hit = other.getHitPoints();
        	this->_energy = other.getEnergy();
        	this->_damage = other.getDamage();

	}
	return *this;
}


std::string	ClapTrap::getName() const{

	return _name;
}

unsigned int	ClapTrap::getHitPoints() const {

	return _hit;
}

unsigned int	ClapTrap::getEnergy() const {

	return _energy;
}

unsigned int	ClapTrap::getDamage() const {

	return _damage;
}

void	ClapTrap::attack( const std::string& target ) {

	std::cout << "ClapTrap [" << _name << "] attacks [" << target << "]";
}

void	ClapTrap::takeDamage( unsigned int amount )  {

	std::cout << ", causing " << amount << " points of damage!" << std::endl;
	if (_hit > amount)
		_hit -= amount;
	else {
		_hit = 0;	
		std::cout << _name << " is dead" << std::endl;
	}
	_damage += amount;

}

void	ClapTrap::beRepaired( unsigned int amount ) {
	
	if (amount > 10)
		return ;
	if (_energy > amount) {
		_energy -= amount;
		_hit += amount;
		std::cout << _name << " is repaired for " << amount << " points" << std::endl;
	}
	else {
		
		std::cout << "[" << _name << "] can't be repaired. Not enough energy" << std::endl << "[" <<  _name << "] is dead" << std::endl;
	}
}

ClapTrap::~ClapTrap() {
	
	std::cout << "Clap destructor for " << _name << " called" << std::endl;
}
