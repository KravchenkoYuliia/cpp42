/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:19:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 15:47:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string givenName ) {

	Zombie*	arrayOfZombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
	
		arrayOfZombies[i].setName(givenName);
	}
	return arrayOfZombies;
}
