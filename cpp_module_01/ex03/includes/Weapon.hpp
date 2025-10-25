/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:32:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/25 18:33:54 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(std::string givenWeapon);
	~Weapon();

	std::string&	getType() const;
	void		setType(const std::string givenWeapon);


private:
	std::string	type;
};

#endif
