/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 14:56:15 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class clapTrap {

public:
	clapTrap();
	clapTrap(std::string inputName);
	clapTrap(std::string inputName, unsigned int inputHealth, unsigned int inputEnergy, unsigned int inputDamage);
	clapTrap(const clapTrap& other);
	clapTrap& operator = (const clapTrap& other);

	~clapTrap();

	std::string	getName() const;

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	void	printPoints( void );
	
private:
	std::string	_name;
	unsigned int		_health;
	unsigned int		_energy;
	unsigned int		_damage;

};


#endif
