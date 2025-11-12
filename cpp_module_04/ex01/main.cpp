/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:22:41 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 13:18:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define animalNumber 5

int	main() {

	for (int i = 0; i < animalNumber / 2; i++) {

		const Animal* dog = new Dog();
		dog->makeSound()
		std::cout << std::endl;
	}

	for (int i = animalNumber / 2 + 1; i < animalNumber; i++) {
		
		const Animal* cat = new Cat();
		std::cout << std::endl;
	}

		

	//delete cat;
	std::cout << std::endl;
	//delete dog;

	return 0;
}
