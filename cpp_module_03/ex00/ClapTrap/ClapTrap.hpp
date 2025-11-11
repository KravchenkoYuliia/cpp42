/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 11:10:33 by yukravch         ###   ########.fr       */
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
