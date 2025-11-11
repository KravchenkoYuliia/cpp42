/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 10:08:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string input);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator = (const ScavTrap& other);
	~ScavTrap();


	void	guardGate();

};

#endif
