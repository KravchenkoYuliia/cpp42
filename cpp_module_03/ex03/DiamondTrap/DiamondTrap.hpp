/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:22:56 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 10:27:58 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

public:
	DiamondTrap();
	DiamondTrap(std::string inputName);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator = (const DiamondTrap& other);
	
	~DiamondTrap();

	void	whoAmI();

private:
	std::string	_name;

};

#endif
