/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:08:56 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/17 10:23:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class AMateria;
class ICharacter {

public:
	virtual std::string const&	getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void			unequip(int idx) = 0;
	virtual void			use(int idx, ICharacter& target) = 0;
	
	virtual	~ICharacter() {}

};

#endif
