/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:22:41 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/13 12:26:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define N 6



void	testArrayOfAnimal() {

	if (N % 2 != 0)
		throw std::runtime_error("Odd number of Animals");

	const Animal*	animals[N];
	for (int i = 0; i < N / 2; i++) {

		animals[i] = new Dog();
		std::cout << "Dog [" << i << "]" << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = N / 2; i < N; i++) {
		
		animals[i] = new Cat();
		std::cout << "Cat [" << i << "]" << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < N; i++) {
	
		std::cout << "Deleting animal [" << i << "]" << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
}


void	testFromSubject() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

}

void	testDeepCopy() {

	std::cout <<  "Creating a cat1" << std::endl;
	Cat	cat1;
	std::cout << "Setting a cat1'a idea: [Find a mouse]" << std::endl;
	cat1.getBrain().setIdea("Find a mouse", 0);
	std::cout << std::endl;

	std::cout << "Copying a cat1 to cat2" << std::endl;
	Cat	cat2 = cat1;
	std::cout << "Setting a cat2'a idea: [Take a nap]" << std::endl;
	cat2.getBrain().setIdea("Take a nap", 0);
	std::cout << std::endl;

	std::cout << "Cat1's idea is [" << cat1.getBrain().getIdea(0) << "]" << std::endl;
	std::cout << "Cat2's idea is [" << cat2.getBrain().getIdea(0) << "]" << std::endl;
	std::cout << std::endl;

}

int	main() {

	try {
		std::cout << std::endl;
		std::cout << "|||||||||||||||||||| TEST 1 ||||||||||||||||||||||" << std::endl << "Create [" << N << "] Animals: half Dogs, half Cats" << std::endl << std::endl;
		testArrayOfAnimal();
		std::cout << std::endl;
		
		std::cout << "||||||||||||||||||| TEST 2 |||||||||||||||||||||||" << std::endl << "Copy of Cat or Dog must be a deep copy" << std::endl << std::endl;
		testDeepCopy();
	}
	catch (std::runtime_error e) {

		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
