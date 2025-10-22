/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:58:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/22 17:48:09 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	announce( void ) {

	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) {

	Zombie test = Zombie::newZombie(std::string test_name);
	Zombie::randomChump(std::string test_name2);
}

Zombie::~Zombie( void ) {

	delete 
}
