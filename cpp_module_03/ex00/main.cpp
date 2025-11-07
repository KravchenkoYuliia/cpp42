/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/07 13:19:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

int	main() {

	clapTrap	Harry("Harry");
	clapTrap	Voldemort("Voldemort");
	clapTrap	Hermione("Hermione");
	
	std::cout << std::endl;
	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
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
	std::cout << std::endl;

	Harry.attack("Voldemort");
	Voldemort.takeDamage(4);
	Voldemort.beRepaired(4);
	std::cout << std::endl;

	return 0;
}
