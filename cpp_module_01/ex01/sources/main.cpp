/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:19:12 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 15:55:02 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {

	int	N = 19;
	Zombie*	arrayOfZombies;

	std::string	name = "arrayOfZombies";
	arrayOfZombies = zombieHorde(N, name);
	std::cout << std::endl;
	
	for (int i = 0; i < N; i++) {

		std::cout << i+1 << ": ";
		arrayOfZombies[i].announce();
	}

	std::cout << std::endl;
	delete[] arrayOfZombies;
	return 0;
}
