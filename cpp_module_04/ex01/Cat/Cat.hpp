/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:24:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:42:41 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {

public:
	Cat();
	Cat(const Cat& other);
	Cat&	operator = (const Cat& other);
	
	void	makeSound() const;
	Brain&	getBrain() const;

	~Cat();

private:
	Brain*	_brain;

};

#endif

