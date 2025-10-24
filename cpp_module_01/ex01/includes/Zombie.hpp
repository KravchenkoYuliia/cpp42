/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:18:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 15:43:57 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {

public:
	Zombie();
	~Zombie();

	void	announce( void );
	void	setName( std::string name );

private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
