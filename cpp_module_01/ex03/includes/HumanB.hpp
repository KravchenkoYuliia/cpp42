/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:32:05 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 19:44:54 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string givenName);
	~HumanB();

	void		attack();
	void		setWeapon(Weapon* givenWeapon);

private:
	Weapon*		weaponB;
	std::string	name;
};

#endif
