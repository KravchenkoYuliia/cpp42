/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:32:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 19:35:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

public:
	HumanA(std::string givenName, Weapon& givenWeapon);
	~HumanA();

	void		attack();

private:
	Weapon&		weaponA;
	std::string	name;
};

#endif
