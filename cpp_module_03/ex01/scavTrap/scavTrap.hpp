/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:31:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 15:15:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "clapTrap.hpp"

class scavTrap: public clapTrap {

public:
	scavTrap();
	scavTrap(std::string input);
	scavTrap (const scavTrap& other);
	scavTrap& operator = (const scavTrap& other);
	~scavTrap();


	void	guardGate();

};

#endif
