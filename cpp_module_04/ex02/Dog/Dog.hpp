/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:24:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:55:36 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {

public:
	Dog();
	Dog(const Dog& other);
	Dog&	operator = (const Dog& other);
	
	void	makeSound() const;
	Brain&	getBrain() const;

	~Dog();

private:
	Brain*	_brain;

};

#endif

