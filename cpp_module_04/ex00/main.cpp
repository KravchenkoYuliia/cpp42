/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:22:41 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:24:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main() {

	Animal	animal;
	std::cout << "Type [" << animal.getType() << "]" << std::endl;
	animal.makeSound();
	std::cout << std::endl;

	Cat	cat;
	std::cout << "Type [" << cat.getType() << "] :" << std::endl;
	cat.makeSound();
	std::cout << std::endl;

	Dog	dog;
	std::cout << "Type [" << dog.getType() << "] :" << std::endl;
	dog.makeSound();
	std::cout << std::endl;
	
	return 0;
}
