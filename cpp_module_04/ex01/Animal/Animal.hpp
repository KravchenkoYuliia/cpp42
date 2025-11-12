/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:54 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 13:08:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

public:
	Animal();
	Animal( const Animal& other );
	Animal&	operator = ( const Animal& other );

	virtual ~Animal();

	std::string	getType() const;
	virtual void	makeSound() const {
		return ;
	};

	virtual Brain*	getBrain() const {

		return NULL;
	}


protected:
	std::string	_type;

};

#endif
