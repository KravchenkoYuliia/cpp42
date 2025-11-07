/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/07 15:44:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "clapTrap.hpp"

class scavTrap: public clapTrap {

public:
	scavTrap();
	scavTrap (const scavTrap& other);
	scavTrap& operator = (const scavTrap& other);
	~scavTrap();
private:
	std::string	_name;
	
};

#endif
