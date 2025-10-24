/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:57:38 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 14:31:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string name = "StackZombie";
	randomChump(name);
	std::cout << std::endl;


	Zombie*	HeapZombie = NULL;
	
	name = "HeapZombie";
	HeapZombie = newZombie(name);
	HeapZombie->announce();
	delete HeapZombie;

	return 0;
}
