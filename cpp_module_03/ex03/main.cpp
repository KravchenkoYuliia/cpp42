/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 16:16:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {

	DiamondTrap	Yo("Diamond");

	std::cout << std::endl;
	Yo.whoAmI();
	std::cout << std::endl;

	return 0;
}


	/* ALL TRAPS
	ClapTrap	Ron("Ron");
	ScavTrap	Harry("Harry");
	FragTrap	Voldemort("Voldemort");
	DiamondTrap	Hermione("Hermione");
	
	std::cout << std::endl;
	Harry.guardGate();
	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	std::cout << std::endl;

	
	Voldemort.highFivesGuys();
	Voldemort.attack("Harry");
	Harry.takeDamage(4);
	Harry.beRepaired(4);
	std::cout << std::endl;
	
	Hermione.whoAmI();
	Hermione.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	std::cout << std::endl;

	Voldemort.highFivesGuys();
	Voldemort.attack("Hermione");
	Hermione.takeDamage(6);
	Hermione.beRepaired(6);
	std::cout << std::endl;

	Harry.attack("Voldemort");
	Voldemort.takeDamage(400);
	Voldemort.beRepaired(400);
	std::cout << std::endl;
	*/



