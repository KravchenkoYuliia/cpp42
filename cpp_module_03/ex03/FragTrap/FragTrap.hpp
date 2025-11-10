/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:49:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 16:15:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string inputName);
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);
	
	~FragTrap();

	void highFivesGuys(void);
};

#endif
