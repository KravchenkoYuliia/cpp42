/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:46:55 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/22 16:57:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

Class Zombie {

	Zombie();
	~Zombie();
public:
	void		announce( void );
	Zombie*		newZombie(std::string name); //create a zombie, name it and return it
	void		randomChump(std::string name); //create a zombie, name it and make it announce itself						       

private:
	std::string	name;

};

#endif
