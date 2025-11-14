/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:54 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 12:39:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal {

public:
	AAnimal();
	AAnimal( const AAnimal& other );
	AAnimal&	operator = ( const AAnimal& other );

	virtual ~AAnimal();

	std::string	getType() const;
	virtual void	makeSound() const = 0;


protected:
	std::string	_type;

};

#endif
