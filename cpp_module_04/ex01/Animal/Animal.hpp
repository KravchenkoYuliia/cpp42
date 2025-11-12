/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:54 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:16:16 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

public:
	Animal();
	Animal( const Animal& other );
	Animal&	operator = ( const Animal& other );

	~Animal();

	std::string	getType() const;
	virtual void	makeSound() const {
		return ;
	}	

protected:
	std::string	_type;

};

#endif
