/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:24:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:18:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal {

public:
	Dog();
	Dog(const Dog& other);
	Dog&	operator = (const Dog& other);
	
	void	makeSound() const;
	~Dog();
};

#endif
