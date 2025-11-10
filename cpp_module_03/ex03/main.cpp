/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 16:17:15 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	
	FragTrap	Harry("Harry");
	FragTrap	Voldemort("Voldemort");
	FragTrap	Hermione("Hermione");
	
	std::cout << std::endl;
	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	std::cout << std::endl;

	
	Voldemort.highFivesGuys();
	Voldemort.attack("Harry");
	Harry.takeDamage(4);
	Harry.beRepaired(4);
	std::cout << std::endl;
	
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
	

	return 0;
}

/* TEST ALL CONSTRUCTORS
	std::cout << "First robot created with name in parameter" << std::endl;
	scavTrap	robot1("First derived robot");
	std::cout << std::endl;
	
	std::cout << "Second robot created with name in parameter" << std::endl;
	scavTrap	robot2("Second derived robot");
	std::cout << std::endl;

	std::cout << "Copy robot created with robot1 in parameter" << std::endl;
	scavTrap	copyRobot(robot1);
	std::cout << std::endl;
	
	std::cout << "Defaul robot created without parameter and take a copy of robot2 with operator [=]" << std::endl;
	scavTrap	defaultRobot = robot2;
	std::cout << std::endl;

	std::cout << "Destructors:" << std::endl;
*/
