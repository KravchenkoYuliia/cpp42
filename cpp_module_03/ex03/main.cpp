/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 14:01:38 by yukravch         ###   ########.fr       */
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

	Yo.attack("Somebody");
	std::cout << std::endl;
	
	return 0;
}
