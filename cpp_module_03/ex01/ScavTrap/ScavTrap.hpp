/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 13:48:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:
	ScavTrap();
	ScavTrap( std::string input );
	ScavTrap ( const ScavTrap& other );
	ScavTrap& operator = ( const ScavTrap& other );
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();

};

#endif
