/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:31:51 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:39:41 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal& other );
	WrongAnimal&	operator = ( const WrongAnimal& other );

	~WrongAnimal();

	std::string	getType() const;
	void		makeSound() const;

protected:
	std::string	_type;

};

#endif
