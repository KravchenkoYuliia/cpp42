/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:19:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 13:19:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character {

public:
	Character();
	Character(const Character& other);
	Character&	operator = (const Character& other);

	std::string const&	getName() const;
	void			equip(AMateria* m);
	void			unequip(int idx);
	void			use(int idx, ICharacter& target);

	~Character();

private:
	std::string const	_name;
	AMateria*		_slot[4];
};

#endif
