/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 13:39:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap( std::string inputName );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator = ( const ClapTrap& other );

	~ClapTrap();

	std::string	getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergy() const;
	unsigned int	getDamage() const;

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	
private:
	std::string	_name;
	unsigned int		_hit;
	unsigned int		_energy;
	unsigned int		_damage;

};

#endif
