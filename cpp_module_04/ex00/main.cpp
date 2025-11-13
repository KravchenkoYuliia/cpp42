/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:22:41 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 11:32:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {

	Animal	animal;
	std::cout << "Type [" << animal.getType() << "]" << std::endl;
	animal.makeSound();
	std::cout << std::endl;

	Cat	cat;
	std::cout << "Type [" << cat.getType() << "] :" << std::endl;
	cat.makeSound();
	std::cout << std::endl;

	Cat	copyCat = cat;
	std::cout << std::endl;

	Dog	dog;
	std::cout << "Type [" << dog.getType() << "] :" << std::endl;
	dog.makeSound();
	std::cout << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	delete meta;

	return 0;
}
