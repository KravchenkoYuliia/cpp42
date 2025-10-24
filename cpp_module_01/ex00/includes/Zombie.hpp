/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:46:55 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 14:23:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {

public:
	Zombie(std::string name);
	~Zombie();
	
	void		announce( void );

private:
	std::string	name;

};

Zombie*		newZombie(std::string name); //create a zombie, name it and return it
void		randomChump(std::string name); //create a zombie, name it and make it announce itself						       
#endif
