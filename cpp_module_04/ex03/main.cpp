/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:50:40 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/17 14:21:31 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main() {
	
	std::cout << "**************TEST FROM THE SUBJECT***************" << std::endl << std::endl;
	MateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	std::cout << "Creating a new materia ICE" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	std::cout << "Creating a new materia CURE" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	
	std::cout << "*******TEST UNEQUIP FUNCTION************" << std::endl << std::endl;
	me->unequip(1);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;
	

	std::cout << "*******TEST A COPY CONSTRUCTOR AND ASSIGNEMENT OPERATOR************" << std::endl << std::endl;
	Character* steve = new Character("Steve");
	Character* copySteve = new Character(*steve);
	Character assignSteve = *steve;
	std::cout << std::endl;
	delete steve;
	delete copySteve;

	return 0;
}
