/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/10 15:25:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"
#include "scavTrap.hpp"

int	main() {
	
	scavTrap	Harry("Harry");
	scavTrap	Voldemort("Voldemort");
	scavTrap	Hermione("Hermione");
	
	std::cout << std::endl;
	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	Harry.guardGate();
	std::cout << std::endl;

	
	Voldemort.attack("Harry");
	Harry.takeDamage(4);
	Harry.beRepaired(4);
	std::cout << std::endl;
	
	Hermione.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	std::cout << std::endl;

	Voldemort.attack("Hermione");
	Hermione.takeDamage(6);
	Hermione.beRepaired(6);
	Hermione.guardGate();
	std::cout << std::endl;

	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
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
